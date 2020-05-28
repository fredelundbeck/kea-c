#include <Arduino.h>
#include "utils.h"

String get_string_from_serial()
{
    while (Serial.available() == 0) 
    {
    }
    return Serial.readString();
}

int get_int()
{
    while (Serial.available() == 0)
    {
    }
    return Serial.parseInt();
}

int get_int_range_force(int min, int max, char* err_msg)
{
    while (true)
    {
        int input = get_int();
        if (input >= min && input <= max)
        {
            return input;
        }
        Serial.println(err_msg);
    }
       
}

void wait_for_btn_push(uint8_t pin, unsigned long delay_ms)
{
    //Loop until detection
    while (true)
    {
        //If we read a HIGH input from pin
        if (digitalRead(pin) == 1)
        {
            //Break out of loop
            break;
        }
        delay(delay_ms);
    }
}