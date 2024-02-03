///@file main.h


#ifndef _MAIN_H
	#define _MAIN_H
	
#include <stdint.h>

/* ----------- V A R I A B L E S   &  C O N S T A N T S  --------------- */




// Defining a macro representing the integer value 0 (used later in arrays containing the patterns)
#define ZERO____PERCENT ((uint8_t) 0)
// Defining a macro representing the integer value 10 (used later in arrays containing the patterns)
#define TEN_____PERCENT ((uint8_t) 10)
// Defining a macro representing the integer value 40 (used later in arrays containing the patterns)
#define FOURTY__PERCENT ((uint8_t) 40)
// Defining a macro representing the integer value 70 (used later in arrays containing the patterns)
#define SEVENTY_PERCENT ((uint8_t) 70)
// Defining a macro representing the integer value 100 (used later in arrays containing the patterns)
#define HUNDRED_PERCENT ((uint8_t) 100)

// Defining a macro storing the number of processes existing in our operating system
#define NUMBER_OF_PROCESSES 8
// Defining a macro storing the number of LEDs available on our platform
#define NUMBER_OF_LEDS 8

// Defining a macro storing the pattern currently in use (changing the token sequence [using the identifier of one of the arrays below] leads to change of pattern)
#define PATTERN smudged_chaser_light_pattern

// Defining an array containing the dim values of LEDs for this pattern
uint8_t led_in_move_light_pattern[14][NUMBER_OF_LEDS] = 
{
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT}
};
	
// Defining an array containing the dim values of LEDs for this pattern
uint8_t right_indicator_light_pattern[8][NUMBER_OF_LEDS] = 
							{
	{HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT}
};

// Defining an array containing the dim values of LEDs for this pattern
uint8_t left_indicator_light_pattern[8][NUMBER_OF_LEDS] = 
{
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT},
	{HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT}
};					

// Defining an array containing the dim values of LEDs for this pattern
uint8_t normal_chaser_light_pattern[6][NUMBER_OF_LEDS] = 
{
	{HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, ZERO____PERCENT}
	};

// Defining an array containing the dim values of LEDs for this pattern	
uint8_t smudged_chaser_light_pattern[16][NUMBER_OF_LEDS] = 
{
	{HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{TEN_____PERCENT, FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, TEN_____PERCENT, FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, TEN_____PERCENT, FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, TEN_____PERCENT, FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, TEN_____PERCENT, FOURTY__PERCENT, SEVENTY_PERCENT, HUNDRED_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, TEN_____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, ZERO____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{ZERO____PERCENT, HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{HUNDRED_PERCENT, SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},
	{SEVENTY_PERCENT, FOURTY__PERCENT, TEN_____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT},

};
			
// Defining a global variable for taking care of a flag which indicates if the "step_counter" was at least once reseted (0 -> false | 1 (or > 0) -> true)
uint8_t is_step_counter_once_reseted = 0;
// Defining a global variable containing the dim values of LEDs
uint8_t dim_values[NUMBER_OF_LEDS] = {ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT, ZERO____PERCENT};
// Defining a global variable for keeping track of the steps
uint8_t step_counter = 0;


// Defining a new type for IDs of processes
typedef uint32_t process_id;

// Defining an enum and a corresponding type whose elements indicate the state of a process
typedef enum  
{
	IDLE,
	RUNNING,
	DESTROYED
} process_state;

// Defining an enum and a corresponding type whose elements indicate the state of a status of a process manipulation action
typedef enum
{
	SUCCESSFULLY_DESTROYED,
	ALREADY_DESTROYED,
	DESTRUCTION_BLOCKED_DURING_EXECUTION
} process_manipulation_status;

// Defining a function pointer and a corresponding type used for pointing to the function of each process
typedef void (*ledx)(uint32_t counter, uint16_t dim_percentage);

// Defining a struct and a corresponding type for process context blocks
typedef struct 
{
	process_id id;
	process_state state;
	ledx process_function;

} process_context_block;

// Creating a list containing the processes available to our operating system
process_context_block process_list[NUMBER_OF_PROCESSES];

/* ------------- F u n c t i o n  P r o t o t y p e s  ----------------- */

// Declaring the "setup"-function whose definition can be found inside of the "main.c"-file
void setup(void);
// Declaring the "update"-function whose definition can be found inside of the "main.c"-file
void update(void);
// Declaring the "dim_specific_led"-function whose definition can be found inside of the "main.c"-file
void dim_specific_led(uint32_t tick_counter, uint16_t dim_percentage, uint8_t pin_number);
// Declaring the "adjust_dim_values"-function whose definition can be found inside of the "main.c"-file
void adjust_dim_values(void);
// Declaring the "create"-function whose definition can be found inside of the "main.c"-file
process_id create(ledx function_of_process_to_create);
// Declaring the "destroy"-function whose definition can be found inside of the "main.c"-file
process_manipulation_status destroy(process_id id_of_process_to_destoroy);

#endif
