#include <stdio.h>
#include <stdlib.h>

//Definition of struct
struct Rectangle
{
    int length;
    int breadth;
    char x;
};
//Definition doesnt consume memory

int main()
{
    struct Rectangle r1;
    //Variable of type Rectangle is created.
    //r1 is local to the main function and consumes memory in main's stack frame

    r1.length = 5;
    r1.breadth = 10;
    r1.x = 'X';

    printf("%lu\n",sizeof(r1));
    //It prints 12 because it is easy for machine to access 4 byte (32 bits)
    //The memory allocated for char in this struct will be 4 bytes, but uses only 1 byte
    //This is called "padding" of memory in structures
    printf("%d %d %c",r1.length,r1.breadth,r1.x);
    return 0;
}
