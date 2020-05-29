#include <Arduino.h>
#include "utils.h"
#include "ardsetup.h"

String get_string_from_serial()
{
    while (!Serial.available()) {}
    return Serial.readString();
}

bool get_yes_no_answer_force(char *err_msg)
{
    while (true)
    {
        String answer = get_string_from_serial();
        if (answer[0] == 'y' || answer[0] == 'Y')
        {
            return true;
        }
        else if (answer[0] == 'n' || answer[0] == 'N')
        {
            return false;
        }
        Serial.println(err_msg);
    }
    
}

int get_int()
{
    //While bits aren't being communicated
    while (!Serial.available()) {}
    return Serial.parseInt();
}

int get_int_range_force(int min, int max, char *err_msg)
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

void led_red_on()
{
    digitalWrite(LED_RED, HIGH);
}

void led_ylw_on()
{
    digitalWrite(LED_YLW, HIGH);
}

void led_grn_on()
{
    digitalWrite(LED_GRN, HIGH);
}

void led_red_off()
{
    digitalWrite(LED_RED, LOW);
}

void led_ylw_off()
{
    digitalWrite(LED_YLW, LOW);
}

void led_grn_off()
{
    digitalWrite(LED_GRN, LOW);
}