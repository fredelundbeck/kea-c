/*
Assignment text:
Make a new program, declare a one dimensional array by the type of int, assign 
the array with the values by using a pointer(s).

     1   2   3   4   5   6   7   8   9  10
    11  12  13  14  15  16  17  18  19  20
Up to
    91  92  93  94  95  96  97  98  99  100

Now call a procedure to make a formatted printout the values from the array. 
Again use pointer(s).
*/

#include <stdio.h>

void print_int_array(int *numbers_ptr, int array_size);

int main(void)
{
    int numbers[100];

    int *n_ptr = numbers;

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
    {
        *(n_ptr+i) = i+1;
    }
    
    print_int_array(n_ptr, 100);

    return 0;
}

void print_int_array(int *numbers_ptr, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", *(numbers_ptr+i));
    }
}

/*
Output:
 1  2  3  4  5  6  7  8  9 10 
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