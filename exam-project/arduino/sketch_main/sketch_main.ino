#include "slotmachine.h"

void setup()
{
  //Setup serial
  Serial.begin(9600);
  
  slotmachine_t* slotmachine = create_slotmachine();

  Serial.println("Hello");
  
}

void loop()
{
    
}
