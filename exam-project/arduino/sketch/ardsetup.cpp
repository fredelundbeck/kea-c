#include <Arduino.h>
#include "ardsetup.h"

void setup_arduino()
{
    //Setup bit rate 
    Serial.begin(9600);

    //Setup pins
    pinMode(BTN_PIN, INPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YLW, OUTPUT);
    pinMode(LED_GRN, OUTPUT);
}