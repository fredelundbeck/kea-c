#include <stdlib.h>
#include "slotmachine.h"

slotmachine_t* create_slotmachine (slotmachine_config_t config, wheel_t wheels[], rule_t rules[], size_t rules_size)
{
    //Allocate dynamic memory for the slotmachine struct.
    slotmachine_t* slotmachine = malloc(sizeof(slotmachine_t));

    //Check if we're out of memory.
    if (slotmachine == NULL)
    {
        return NULL;
    }

    //Assign config to passed config.
    slotmachine->config = config;

    //Assign wheels array to passed wheels.
    for (size_t i = 0; i < MAX_WHEELS; i++)
    {
        slotmachine->wheels[i] = wheels[i];
    }
    
    //Assign rules array to passed rules.
    for (size_t i = 0; i < rules_size; i++)
    {
        slotmachine->rules[i] = rules[i];
    }

    return slotmachine;
}

slotmachine_config_t* create_slotmachine_config (int spin_credit_price, float usd_credit_conversion)
{
    //Allocate dynamic memory for the slotmachine-config struct.
    slotmachine_config_t* config = malloc(sizeof(slotmachine_config_t));

    //Check if we're out of memory.
    if (config == NULL)
    {
        return NULL;
    }
    
    //Assign spin credit price to corresponding argument.
    config->spin_credit_price = spin_credit_price;

    //Assign USD credit conversion to corresponding struct.
    config->usd_to_credit_conversion = usd_credit_conversion;

    return config;
}

wheel_t* create_wheel (symbol_t symbols[])
{
    //Allocate dynamic memory for the wheel struct.
    wheel_t* wheel = malloc(sizeof(wheel_t));

    //Check if we're out of memory.
    if (wheel == NULL)
    {
        return NULL;
    }

    //Assign current symbol to 0.
    wheel->current_symbol = 0;
    
    //Assign symbols array to passed symbols.
    for (size_t i = 0; i < MAX_SYMBOLS; i++)
    {
        wheel->symbols[i] = symbols[i];
    }
    
    //Return the wheel 
    return wheel;
}

rule_t* create_rule (symbol_t symbols[], int price)
{
    //Allocate dynamic memory for the rule struct.
    rule_t* rule = malloc(sizeof(rule_t));

    //Check if we're out of memory.
    if (rule == NULL)
    {
        return NULL;
    }

    //Assign price to passed price.
    rule->price = price;

    //Assign symbols array to passed symbols.
    for (size_t i = 0; i < MAX_WHEELS; i++)
    {
        rule->symbols[i] = symbols[i];
    }
    
    return rule;
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