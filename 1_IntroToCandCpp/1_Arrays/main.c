#include <stdio.h>
#include <stdlib.h>


int main()
{
    int A[10] = {2,4,6,8,10,12,14,16};
    int n,Array[n];

    printf("%d\n",sizeof(A));
    printf("%d",A[8]); //REst of the elements are initialised by 0s

    for(int i=0;i<10;i++)
    {
        printf("\n%d",A[i]);
    }

    printf("Enter the size of Array:\n");
    scanf("%d",&n);

    A[0] = 2;


    for(int i=0;i<n;i++)
    {
        printf("\n%d",Array[i]);
    }


    return 0;
}

//1. Variable sized arrays can be created but cannot be initialised
//2. Variable sized arrays may not work properly with all compilers
