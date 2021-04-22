#include <stdio.h>
#include <stdlib.h>

void fun(int *A,int n) //Arrays are always passed and received by address
{
    printf("\n%d\n",sizeof(A)/sizeof(int)); //Prints size as 2 because A is just an integer pointer

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
}

int * createArray(int n)
{
    int *p;
    p = (int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        p[i]=i+1;

    return p;
}

int main()
{
    int A[] = {2,4,6,8,10};
    int n=5;

    for(int i=0;i<5;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n**************\n");


    /************Pass array as a pointer***************/
    fun(A,n);
    printf("\n**************\n");


    /*********Receive and Array from a function*********/
    int *arrayPointer,size=5;
    arrayPointer = createArray(size);
    for(int i=0;i<size;i++)
        printf("%d ",arrayPointer[i]);

    free(arrayPointer);

    return 0;
}

//Notes
//1. Since Arrays are passed by value only, any change made in the called function to the array, it will reflect into the actual array
