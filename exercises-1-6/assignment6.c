/*
Assignment text:
Make a program where you enter a number into the main function.
Make a function to input a parameter as the number from the main routine.
Inside the function make a math command ex multiply the number by itself, and 
then return the result.
*/

#include <stdio.h>

int multiply(int a, int b);

int main(void)
{
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d * %d = %d\n", a, b, multiply(a,b));

    return 0;
}

int multiply(int a, int b)
{
    return a*b;
}

/*
Input:
5
2

Output:
5 * 2 = 10
*/