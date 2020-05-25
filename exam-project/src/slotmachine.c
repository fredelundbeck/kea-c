#include <stdlib.h>
#include "slotmachine.h"

slotmachine_t* create_slotmachine (slotmachine_config_t config, wheel_t wheels[], rule_t rules[])
{
    return NULL;
}

slotmachine_config_t* create_slotmachine_config (int spin_credit_price, float usd_credit_conversion)
{
    return NULL;
}

wheel_t* create_wheel (symbol_t symbols[])
{
    //Allocate memory for the wheel struct
    wheel_t* wheel = malloc(sizeof(wheel_t));

    //Check if we're out of memory
    if (wheel == NULL)
    {
        return NULL;
    }

    //Assign current symbol to 0
    wheel->current_symbol = 0;
    
    //Assign symbols array to passed symbols
    for (size_t i = 0; i < MAX_SYMBOLS; i++)
    {
        wheel->symbols[i] = symbols[i];
    }
    
    //Return the wheel 
    return wheel;
}

rule_t* create_rule (symbol_t symbols[], int price)
{
    return NULL;
}

slotmachine_t* create_default_slotmachine ()
{
    return NULL;
}

void destroy_slotmachine (slotmachine_t *slotmachine)
{
    //todo: find out if free'ing the slotmachine pointer is enough?
    free(slotmachine);
}