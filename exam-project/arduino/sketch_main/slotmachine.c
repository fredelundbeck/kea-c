#include "slotmachine.h"

slotmachine_t* create_slotmachine()
{
  slotmachine_t* temp = malloc(sizeof(slotmachine_t));
  temp->age = 32;
  return temp;
}
