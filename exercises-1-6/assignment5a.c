/*
Make a program where you input a character;
If the character is an “a” or “A” the program will printout “Apple”;
If the character is an “b” or “B” the program will printout “Banana”;
If the character is an “c” or “C” the program will printout “Cherry”;
If the character is an “d” or “D” the program will printout “Date”;
If the character is an “e” or “E” the program will printout “Elderberry”;
Otherwise the program will answer “I don’t know any fruit with a ” the entered letter.
Use if-else.
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