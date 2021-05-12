#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    /*Direct declaration of a 2-D array*/
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //Will be created inside stack

    /* Declaring an array of pointers and pointing to arrays in heap to form a 2D Array*/
    int *B[3]; //Created in stack
    B[0] = (int *)malloc(4*sizeof(int));
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

    /*Declaring a double pointer and creating array of pointers and arrays in heap */
    int **c;
    c = (int **)malloc(3 * sizeof(int *));

    c[0] = (int *)malloc(4 * sizeof(int));
    c[1] = (int *)malloc(4 * sizeof(int));
    c[2] = (int *)malloc(4 * sizeof(int));

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",A[i][j]);

        printf("\n");
    }

    printf("*****************************\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",B[i][j]);

        printf("\n");
    }

    printf("*****************************\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",c[i][j]);

        printf("\n");
    }

    for(i=0;i<3;i++)
        free(B[i]);

    for(i=0;i<3;i++)
        free(c[i]);

    free(c);


    return 0;
}
