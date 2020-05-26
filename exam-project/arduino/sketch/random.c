#include <stdlib.h>
#include <stdbool.h>
#include "random.h"

bool seeded = false;

int get_random_int(int min, int max)
{
    //Check if rand hasn't been seeded
    if (!seeded)
    {   
        //Seeds with time since 00:00:00 UTC Jan 1, 1970 (Unix timestamp) in seconds.
        srand(time(0));
        seeded = true;
    }
    
    //Returns the rand result clamped between min & max.
    return (rand() % (max + abs(min) + 1)) + min;
} 