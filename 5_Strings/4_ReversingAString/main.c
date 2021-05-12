#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "Python";
    int i=0,j=0;
    char temp;

    while(A[j]!='\0')
    {
        j++;
    }
    j--;

    while(i<j)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        i++;
        j--;
    }
    printf("%s\n",A);
    return 0;
}
