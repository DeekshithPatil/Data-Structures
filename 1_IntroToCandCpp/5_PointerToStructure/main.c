#include <stdio.h>
#include <stdlib.h>


struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct Rectangle r = {10,5}; //In C++ writing struct here is not mandatory

    printf("%d %d\n",r.length,r.breadth);

    /**Pointer to Struct*/
    struct Rectangle *p = &r;

    printf("%d %d\n",p->length,p->breadth);
    printf("\n********************\n");

    /**** Structure in heap******/
    struct Rectangle *heapPointer;
    heapPointer = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    heapPointer->length = 15;
    heapPointer->breadth = 7;

    printf("%d %d\n",heapPointer->length,heapPointer->breadth);

    free(heapPointer);



    return 0;
}
