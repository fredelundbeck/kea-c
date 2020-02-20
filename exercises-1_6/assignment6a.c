/*
Assignment text:
Change the program developed in Assignment 6 so it has a:
main file AND .c an .h file with the procedure 
int min(int a,int b)
*/
    #include <stdio.h>
    #include "assignment6a-files/assignment6a_math.h"

    int main(void)
    {
        int a, b;

        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d * %d = %d\n", a, b, multiply(a,b));

        return 0;
    }

/*
Input:
5
2

Output:
5 * 2 = 10
*/