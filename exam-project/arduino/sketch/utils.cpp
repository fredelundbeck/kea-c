#include <Arduino.h>

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