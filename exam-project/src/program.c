#include <stdio.h>
#include "slotmachine.h"

int main()
{
    //Create default slot machine
    slotmachine_t* slotmachine = create_default_slotmachine();

    //Free the dynamic memory allocated for the slot machine
    destroy_slotmachine(slotmachine);

    return 0;
}