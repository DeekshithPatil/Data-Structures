#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

void fun1(struct Rectangle r) //The received structure is copied into r
{
    r.length = 100;
    r.breadth = 200;
    printf("\n%d %d\n",r.length,r.breadth);
}

void fun2(struct Rectangle * r) //Only address of structure is received
{
    r->length = 50;
    r->breadth = 100;

    printf("\n%d %d\n",r->length,r->breadth);
}

struct Rectangle * fun3()
{
    struct Rectangle *p;
    p = (struct Rectangle *) malloc(sizeof(struct Rectangle));

    return p;
}

int main()
{
    struct Rectangle r={10,5};

    /************Call by Value **************/
    fun1(r);
    printf("\n****************\n");

    /************Call by Address **********/
    fun2(&r);
    printf("\n****************\n");

    printf("%d %d\n",r.length,r.breadth);

    printf("\n****************\n");

    /********Receive a Structure from a function*******/
    struct Rectangle * structPointer;
    structPointer = fun3();

    structPointer->length = 1000;
    structPointer->breadth = 999;

    printf("\n%d %d\n",structPointer->length,structPointer->breadth);

    free(structPointer);



    return 0;
}

//NOTES
//1. When we pass structure to a function by value, then all the individual data elements also get copied
