/*
Assignment text:
Now try to make the same program with a “switch” command.
*/

#include <stdio.h>
#include <ctype.h>

void print_fruit(char c);

int main(void)
{

    print_fruit('A');
    print_fruit('X');

    return 0;
}

void print_fruit(char c)
{
    switch (toupper(c))
    {
        case 'A':
            printf("Apple\n");
            break;
        case 'B':
            printf("Banana\n");
            break;
        case 'C':
            printf("Cherry\n");
            break;
        case 'D':
            printf("Date\n");
            break;
        case 'E':
            printf("Elderberry\n");
            break;
        default:
            printf("I don't know any fruit with a %c\n", c);
            break;
    }
}

/*
Output:
Apple
I don't know any fruit with a X
*/