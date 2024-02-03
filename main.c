///@file main.c


/**************************************************************************
 *  COPYRIGHT (C) Peter Raab  2019                                        *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  PROJECT       EBSy: Px - Basisproject                                 *
 *  MODULE        main.c                                                  *
 *  REVISION      2.0                                                     *
 **************************************************************************
 *  PURPOSE:                                                              *
 *   The main routine is the start of every C-program. The purpose of     *
 *   the main is to initialize the hardware and start the operation       *
 *   system.                                                              *
 *                                                                        *
 **************************************************************************
 *  REMARKS:                                                              *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author      Description                       *
 *     1.0      06.09.2019   P. Raab     creation                         *
 *     2.0      04.01.2021   P. Raab     port to stm32G474                *
 *                                                                        *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */

#include <stdint.h>
#include "stm32g474xx.h"
#include "delay.h"
#include "main.h"


/**
Function used for adjusting dim values of LEDs.

Adjusting dim values of all LEDs by accomplishing following tasks:
	- Iterating over all dim values available in current step of the pattern
	- Handling the special cases
	- Assigning the proper dim values to each element of the "dim_values"-array whose elements correspond to dim values of LEDs

@param[in] void
@param[out] void

*/
void adjust_dim_values(void)
{
	// Iterating over all elements of the "dim_values"-array
	for(int i = 0; i < NUMBER_OF_LEDS; i++)
	{
		// Checking whether the "smudged_chaser_light_pattern" is currently activated (special case handling)
		if(PATTERN == smudged_chaser_light_pattern)
		{
			// Checking whether the "step_counter" is at least one reseted
			if(is_step_counter_once_reseted == 1)
			{
				// Checking whether we are in the first 2 steps (steps with index 0 and 1)
				if(step_counter < 2)
				{
					// Skipping the first 2 steps (a cycle of this pattern starts with the step with index 2)
					step_counter += 2;
				}
			}		
		}
		// Assigning the proper dim value to each LED
		dim_values[i] = PATTERN[step_counter][i];
	}
}

/* ----------------------- F U N C T I O N S  -------------------------- */

/**
Function defined as a part of out API for creating a new process.

Creating a new process by accomplishing following tasks:
	- Creating a new instance of the "process_context_block" and assigning an ID, a state and the given function pointer to it
	- Adding the created instance to the list of the processes

@param[in] ledx function_of_process_to_create (function pointer to the function for which we will create a process)
@param[out] process_id (ID of the process created)

*/
process_id create(ledx function_of_process_to_create)
{
	// Defining a static variable for keeping track of the process ids generated
	static uint32_t current_process_id = 0;
	// Creating a new instance of the process context block and assigning values to its members
	process_context_block process_context_block_for_process_to_create = {current_process_id, IDLE, function_of_process_to_create};
	// Adding the created instance to the list of the processes
	process_list[current_process_id] = process_context_block_for_process_to_create;
	// Returning the generated process id and increasing it so that we have always unique IDs
	return current_process_id++;
}

/**
Function defined as a part of our API for destroying a process.

Destroying a process by accomplishing following tasks:
	- Getting the process context vlock of the process which should be destroyed with the given ID from the processes list
	- Taking a decision whether the process can be destroyed or not by checking these 2 cases:
		- Checking whether a process is already destroyed
			-> Returning a manipulation status indicating that the process is already destroyed.
		- Checking whether a process is currently running
			-> Returning a manipulation status indicating the the process is currently running and can not get destroyed consequently. 
		- Destroying the process if non of above mentioned cases are applicable

@param[in] process_id id_of_process_to_destoroy (parameter containing the ID for identifying the process to destroy)
@param[out] process_manipulation_status (status of the manipulation [in this case destruction]-action)

*/
process_manipulation_status destroy(process_id id_of_process_to_destoroy)
{
	// Getting the process context vlock of the process which should be destroyed with the given ID from the processes list
	process_context_block process_to_destroy = process_list[id_of_process_to_destoroy];
	
	// Checking whether a process is already destroyed
	if(process_to_destroy.state == DESTROYED)
	{
		// Retruning the "ALREADY_DESTROYED" as the status of the manipulation indicating that a process can not get destroyed multiple times.
		return ALREADY_DESTROYED;
	}
	// Checking whether a process is currently running
	else if(process_to_destroy.state == RUNNING)
	{
		// Retruning the "DESTRUCTION_BLOCKED_DURING_EXECUTION" as the status of the manipulation indicating that the process can not get destroyed during its execution.
		return DESTRUCTION_BLOCKED_DURING_EXECUTION;
	}
	// Destroying the process if non of upper mentioned cases are applicable
	else
	{
		// Assigning the "DESTROYED" state to the process indicating that the proces is destroyed
		process_to_destroy.state = DESTROYED;
		// Retruning the "SUCCESSFULLY_DESTROYED" as the status of the manipulation indicating that the process is destroyed successfully.
		return SUCCESSFULLY_DESTROYED;
	}
}

/**
Function used for actual dimming of a specific LED.

Dimming a specific LED by checking these 2 cases:
	- Checking whether we have a non-zero dimming percentage and we are at the beginning of our time base
		-> Turning on the LED
	- Checking whether we reached the duty cycle desired
		-> Turning off the LED

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[in] uint8_t pin_number (parameter storing the number of the GPIO-pin to which a LED is assigned)
@param[out] void

*/
void dim_specific_led(uint32_t tick_counter, uint16_t dim_percentage, uint8_t pin_number)
{
	// Checking whether we have a non-zero dimming percentage and we are at the beginning of our time base
	if(tick_counter == 0 && dim_percentage != 0)
	{
		// Turning on the corresponding LED
		GPIOA->ODR |= (1 << pin_number);
	}
	// Checking whether we reached the duty cycle desired
	else if(tick_counter == dim_percentage)
	{
		// Turning off the corresponding LED
		GPIOA->ODR &= ~(1 << pin_number);
	}
}

/**
Function representing the process for the LED with index 0.

Dimming the LED with index 0 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led0(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 0);
}

/**
Function representing the process for the LED with index 1.

Dimming the LED with index 1 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led1(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 1);
}

/**
Function representing the process for the LED with index 2.

Dimming the LED with index 2 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led2(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 2);
}

/**
Function representing the process for the LED with index 3.

Dimming the LED with index 3 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led3(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 3);
}

/**
Function representing the process for the LED with index 4.

Dimming the LED with index 4 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led4(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 4);
}

/**
Function representing the process for the LED with index 5.

Dimming the LED with index 5 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led5(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 5);
}

/**
Function representing the process for the LED with index 6.

Dimming the LED with index 6 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led6(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 6);
}

/**
Function representing the process for the LED with index 7.

Dimming the LED with index 7 by calling the corresponding function ("dim_specific_led").

@param[in] uint32_t tick_counter (parameter containing the current value of the counter used for keeping trak of time base)
@param[in] uint16_t dim_percentage (parameter representing the dimming value of this LED)
@param[out] void

*/
void led7(uint32_t tick_counter, uint16_t dim_percentage)
{
	dim_specific_led(tick_counter, dim_percentage, 7);
}

/**
Function used for taking care of inital setup and configurations.

Taking care of configurations and initial setup by accomplishing following tasks:
	- Enabling the clock for GPIOA
	- Configuring the first 8 pins of GPIOA as output-pins
	- Turning all leds off
	- Create 8 processes (one process for each LED) by calling the "create"-function from the API

@param[in] void
@param[out] void

*/
void setup(void)
{
	
	// Enabling the clock for GPIOA
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	
	// Configuring the first 8 pins of GPIOA as output-pins (using the masking-method)
	GPIOA->MODER &= 0xFFFF0000;
	GPIOA->MODER |= 
					GPIO_MODER_MODE0_0 |
					GPIO_MODER_MODE1_0 |
					GPIO_MODER_MODE2_0 |
					GPIO_MODER_MODE3_0 |
					GPIO_MODER_MODE4_0 |
					GPIO_MODER_MODE5_0 |
					GPIO_MODER_MODE6_0 |
					GPIO_MODER_MODE7_0;
	
	// Turning off all LEDs
	GPIOA->ODR = 0x0000;
	
	// Creating processes for all LEDs by calling the corresponding function ("create"-function) from our API
	
	// Creating a process for the LED with index 0 (first LED)
	create(&led0);
	// Creating a process for the LED with index 1
	create(&led1);
	// Creating a process for the LED with index 2
	create(&led2);
	// Creating a process for the LED with index 3
	create(&led3);
	// Creating a process for the LED with index 4
	create(&led4);
	// Creating a process for the LED with index 5
	create(&led5);
	// Creating a process for the LED with index 6
	create(&led6);
	// Creating a process for the LED with index 7 (last LED)
	create(&led7);
}


/**
Function used for keeping the program running by using an infinite loop and containing the main logic of the operating system.

Keeping the program up and running by using an infinite loop (wehile(1/true)).

Taking care of the main logic of our operating system by accomplishing following tasks:
	- Keeping track of/manipulating various counters (related to delay, number of steps and time base)
	- Adjusting the dim values of LEDs by calling the corresponding function
	- Calculating the maximum number of step numbers available in this pattern
	- Running/activating the processes

@param[in] void
@param[out] void

*/
void update(void)
{
	// Defining a variable as a counter for controlling the delay between steps 
	uint32_t delay_counter = 0;
	// Defining a variable as a counter for keeping track of the steps
//	uint8_t step_counter = 0;
	// Defining a variable as a counter for controlling the time base of our program (used as time base for dimming-functionality)
	uint32_t tick_counter = 0;
	// Defining a variable for storing the maximum number of steps depending on the pattern currently used
	uint8_t maximum_number_of_steps = 0;

	
	// Infinite loop for keeping the program running so that our program does not reach its end
	while(1)
	{
		// Iterating over the processes in our process list (table)
		for(int i = 0; i < NUMBER_OF_PROCESSES; i++)
		{
			// Adjusting the dim values of all LEDs
			adjust_dim_values();
			// Calculating the maximum number of steps depending on the pattern currently used
			maximum_number_of_steps = sizeof(PATTERN) / sizeof(PATTERN[0]);
			// Running/Activating the corresponding process
			process_list[i].process_function(tick_counter, dim_values[(NUMBER_OF_LEDS - 1) - i]);
		}

		// Increasing the counter used for controlling the time base of our program
		tick_counter++;	
		// Checking whether we reached the maximum value of the counter
		if(tick_counter == 100)
		{
			// Reseting the time base
			tick_counter = 0;
			
			// Checking whether we reached the delay desired 
			if(delay_counter == 50)
			{
				// Checking whether we reached the maximum number of steps
				if(step_counter == (maximum_number_of_steps - 1))
				{
					// Setting the "is_step_counter_once_reseted"-flag to true (1) 
					is_step_counter_once_reseted = 1;
					// Reseting the "step_counter"
					step_counter = 0;
				}
				else
				{
					// Increasing the number of steps we went through
					step_counter++;
				}
				// Reseting the "delay_counter"
				delay_counter = 0;
			}
			else
			{
				// Increasing the "delay_counter"
				delay_counter++;
			}
		}
	}
}


/* --------------  S t a r t    o f    p r o g r a m  -----------------  */
/**
Function used as the entry point of the application.

Calling following functions: 
	- setup
	- update

@param[in] void
@param[out] int (exit-code)

*/
int main(void)
{
	setup();
	update();
}
