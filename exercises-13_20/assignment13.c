/*
Make a C program which can print out the content of a struct 
as mentioned above.
This is going to be used for test purposes.
*/

#include <stdio.h>

typedef struct Author
{
    char *name;
} author_t;

typedef struct Book 
{
    char *name;
    author_t author;
} book_t;

int main(void)
{
    author_t author;
    author.name = "Stephen King";

    book_t book;
    book.name = "It";
    book.author = author;

    printf("%s by %s", book.name, book.author.name);

    return 0;
}


/*
*/