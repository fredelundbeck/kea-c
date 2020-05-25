#ifndef __SLOTMACHINE_H__
#define __SLOTMACHINE_H__

#pragma region type_definitons

/*
This enum represents each symbol available in the wheels.
*/
typedef enum symbol 
{
    APPLE,
    BAR
    BELL,
    CHERRY,
    GRAPE,
    LEMON,
    ORANGE,
    PLUM,
};

/*
This struct represents the slotmachine.
It holds a maximum of 3 wheels.
*/
typedef struct slotmachine
{   
    slotmachine_configuration_t settings;
    wheel_t wheels[3];
} slotmachine_t;

/*
Represents the various settings in the slotmachine:
US dollars to credit conversion, price per spin etc.
*/
typedef struct slotmachine_configuration
{
    int spin_credit_price;
    float usd_to_credit_conversion;
} slotmachine_configuration_t;

/*
This struct represents the wheel in the slotmachine.
A wheel holds an array of 10 symbols & an integer
that tells which symbol is the current one.
*/
typedef struct wheel
{
    int current_symbol;
    symbol symbols[10];
} wheel_t;

/*
This struct represents the rules of the slotmachine i.e 
which order of symbols - when rolled - pays back.
*/
typedef struct rule 
{
    symbol symbols[3];
    int price;
} rule_t;

#pragma endregion type_definitions

#pragma region type_functions



#pragma endregion type_functions

#endif // __SLOTMACHINE_H__