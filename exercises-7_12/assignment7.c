/*
Assignment text:
Make a program with two variables of the type int x=10 and y=20.
We would like to let the program printout the value in the variable, as well as the 
address.
*/

#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;

    int *x_ptr = &x;
    int *y_ptr = &y;

    printf("Values of x & y:\t %d, %d\n"
           "Addresses of x & y:\t 0x%p, 0x%p\n",
           x, y, x_ptr, y_ptr);

    return 0;
}

/*
Output:
Values of x & y:         10, 20
Addresses of x & y:      0x000000000061FE0C, 0x000000000061FE08
*/