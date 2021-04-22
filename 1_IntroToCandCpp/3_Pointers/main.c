#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a=10;
    int *p;

    p = &a;

    printf("%d %u\n",*p,p);

    printf("*******\n");

    /******** Pointer to an array *******/
    int A[5] = {2,4,6,8,10};
    int *arrayPointer;

    arrayPointer = A; //A returns the starting address of array

    for(int i=0;i<5;i++)
    {
        printf("%d\n",*arrayPointer);
        arrayPointer++;
    }

    printf("*******\n");

    /*********Pointer to an array in Heap******/

    int *heapArrayPointer = (int *)malloc(5*sizeof(int));
    heapArrayPointer[0] = 1;
    heapArrayPointer[1] = 1;
    heapArrayPointer[2] = 1;
    heapArrayPointer[3] = 1;
    heapArrayPointer[4] = 1;

    for(int i=0;i<5;i++)
    {
        printf("%d\n",*heapArrayPointer);
        heapArrayPointer++;
    }
    free(heapArrayPointer[5]);

    return 0;
}

//NOTE: Size of a pointer is independent of its data type
