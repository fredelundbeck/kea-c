/*
Assignment text:
Take the program/code from Assignment 8 and change ANY index reference to an 
array position so you use pointers instead.
*/

#include<stdio.h>
void swap(int *a, int *b);

int main()
{
    int i, j, n;
    int ar[] = { 7, 3, 9, 2, 11 };


    printf("Array before sort:\n\n");
    for(i = 0; i < 5; i++)
    {
        printf("ar[%d]=%d\n", i, *(ar+i));
    }

    n=5;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(*(ar+j) > *(ar+j+1))
            {
                swap(&*(ar+j), &*(ar+j+1));
            }
        }
    }
    printf("Array after sort:\n\n");
    for(i = 0; i < 5; i++)
    {
        printf("ar[%d]=%d\n", i, *(ar+i));
    }
    
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
Output:
Array before sort:

ar[0]=7
ar[1]=3
ar[2]=9
ar[3]=2
ar[4]=11
Array after sort:

ar[0]=2
ar[1]=3
ar[2]=7
ar[3]=9
ar[4]=11
*/