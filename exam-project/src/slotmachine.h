#ifndef __SLOTMACHINE_H__
#define __SLOTMACHINE_H__

#define MAX_WHEELS 3
#define MAX_SYMBOLS 10

#pragma region type_definitons

/*
This enum represents each symbol available in the wheels.
*/
typedef enum 
{
    APPLE,
    BAR,
    BELL,
    CHERRY,
    GRAPE,
    LEMON,
    ORANGE,
    PLUM
} symbol_t;

/*
Represents the various settings in the slotmachine:
US dollars to credit conversion, price per spin etc.
*/
typedef struct slotmachine_config
{
    int spin_credit_price;
    float usd_to_credit_conversion;
} slotmachine_config_t;

/*
This struct represents the wheel in the slotmachine.
A wheel holds an array of 10 symbols & an integer
that tells which symbol is the current one.
*/
typedef struct wheel
{
    int current_symbol;
    symbol_t symbols[MAX_SYMBOLS];
} wheel_t;

/*
This struct represents the rules of the slotmachine i.e 
which order of symbols - when rolled - pays back.
*/
typedef struct rule 
{
    symbol_t symbols[MAX_WHEELS];
    int price;
} rule_t;

/*
This struct represents the slotmachine.
It holds a maximum of 3 wheels.
*/
typedef struct slotmachine
{   
    wheel_t wheels[MAX_WHEELS];
    slotmachine_config_t settings;
    rule_t rules[];
} slotmachine_t;

#pragma endregion type_definitions

#pragma region type_functions

/*
The create functions for the slotmachine structures. 
These functions all allocate memory, for each struct,
then initializes them with given arguments and returns
the pointer.
*/

slotmachine_t* create_slotmachine (slotmachine_config_t config, wheel_t wheels[], rule_t rules[]);
slotmachine_config_t* create_slotmachine_config (int spin_credit_price, float usd_credit_conversion);
wheel_t* create_wheel (symbol_t symbols[]);
rule_t* create_rule (symbol_t symbols[], int price);

/*
Creates a slotmachine struct with hardcoded values specific to the
assignment requirements. See README for more information.
*/
slotmachine_t* create_default_slotmachine ();

/*
Function which deallocates the allocated memory for the slotmachine
*/
void destroy_slotmachine(slotmachine_t *slotmachine);

#pragma endregion type_functions

#endif // __SLOTMACHINE_H__