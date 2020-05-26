#include <stdlib.h>
#include "slotmachine.h"

slotmachine_t* create_slotmachine (slotmachine_config_t* config, wheel_t* wheels[], rule_t* rules[], size_t rules_size)
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
    //Create symbol arrays for wheels
    symbol_t symbols[MAX_WHEELS][MAX_SYMBOLS] = {
        { PLUM, BAR, BAR, BAR, LEMON, LEMON, BELL, APPLE, APPLE, APPLE, APPLE, APPLE, APPLE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, CHERRY, CHERRY },
        { PLUM, BAR, BAR, LEMON, LEMON, BELL, BELL, BELL, BELL, BELL, APPLE, APPLE, ORANGE, ORANGE, ORANGE, CHERRY, CHERRY, CHERRY, CHERRY, CHERRY },
        { PLUM, BAR, LEMON, LEMON, BELL, BELL, BELL, BELL, BELL, BELL, BELL, BELL, APPLE, APPLE, ORANGE, ORANGE, GRAPE, GRAPE, GRAPE, GRAPE } 
    };
        
    //Create wheel array & pass each wheel their corresponding symbol arrays
    wheel_t* wheels[MAX_WHEELS] = {
        create_wheel(symbols[0]),
        create_wheel(symbols[1]),
        create_wheel(symbols[2])
    };

    //Declare and assign slotmachine config variables.
    int spin_credit_price = 5;
    float usd_credit_conversion = 10;

    //Create config struct with config variables.
    slotmachine_config_t* config = create_slotmachine_config(spin_credit_price, usd_credit_conversion);

    /* 
    Create rule combinations for the rule structs below. 
    -1 is a wildcard (connects with everything) 
    */
    symbol_t combinations[][MAX_WHEELS] = {
        { CHERRY, -1, -1 },
        { CHERRY, CHERRY, -1 },
        { ORANGE, ORANGE, BAR },
        { ORANGE, ORANGE, ORANGE },
        { APPLE, APPLE, BAR },
        { APPLE, APPLE, APPLE },
        { BELL, BELL, BAR },
        { BELL, BELL, BELL },
        { LEMON, LEMON, BAR },
        { LEMON, LEMON, LEMON },
        { BAR, BAR, BAR },
        { PLUM, PLUM, PLUM }
    };

    //Create rule arrays with combinations from above
    rule_t* rules[] = {
        create_rule(combinations[0], 2),
        create_rule(combinations[1], 5),
        create_rule(combinations[2], 10),
        create_rule(combinations[3], 10),
        create_rule(combinations[4], 14),
        create_rule(combinations[5], 14),
        create_rule(combinations[6], 18),
        create_rule(combinations[7], 18),
        create_rule(combinations[8], 50),
        create_rule(combinations[9], 50),
        create_rule(combinations[10], 50),
        create_rule(combinations[11], 100)
    };

    //Create the slotmachine struct with above data
    slotmachine_t* slotmachine = create_slotmachine(config, wheels, rules, sizeof(rules) / sizeof(rule_t));

    return slotmachine;
}

void destroy_slotmachine (slotmachine_t *slotmachine)
{
    //Free every struct pointer from the slotmachine & itself at last.
    free(slotmachine->config);
    free(slotmachine->rules);
    free(slotmachine->wheels);
    free(slotmachine);
}