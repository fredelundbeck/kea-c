#include <Arduino.h>
#include "utils.h"

String get_string_from_serial()
{
    while (Serial.available() == 0) 
    {
    }
    return Serial.readString();
}

int get_int_from_serial()
{
    while (Serial.available() == 0)
    {
    }
    return Serial.parseInt();
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