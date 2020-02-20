/*
Assignment text:
Take the array of pointers from Assignment 11 and make a new pointer 
to point to any of the 10 pointers in the array. 
Make this pointer circular. 
That is, if you add 1 to the 10th array reference, the result must be the 1st array.
Make a check printout, both of this pointer and the pointer it points to.
*/

#include <stdio.h>

int main(void)
{
    int number_arrays[10][10];
    int *pointers[10];
    int **ptr = &pointers[0];

    for (int i = 0; i < 10; i++)
    {
        *(pointers + i) = *(number_arrays + i);

        for (int j = 0; j < 10; j++)
        {
            *(*(pointers + i) + j) = i * 10 + j + 1;
            printf("%d ", *(*(ptr + i) + j)); 
        }
        printf("\n");
    }

}

/*
Output:
1 2 3 4 5 6 7 8 9 10 
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60 
61 62 63 64 65 66 67 68 69 70
71 72 73 74 75 76 77 78 79 80
81 82 83 84 85 86 87 88 89 90
91 92 93 94 95 96 97 98 99 100
*/