#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "Hello how are you";
    int i,count = 0;

    for(i=0;A[i]!='\0';i++)
    {
        if(A[i] == ' ' && A[i-1]!=' ')
            count++;
    }

    printf("Number of words = %d\n",count+1);
    return 0;
}
