#include <stdio.h>
#include <stdlib.h>

/*Program to check if the string contains only ALphabets and numbers */
int main()
{
    char A[] = "Anil321";
    printf("%d\n",validate(A));
    return 0;
}

int validate(char * A)
{
    int i;

    for(i=0;A[i]!='\0';i++)
    {
        if(!(A[i]>='A' && A[i]<='Z') && !(A[i]>='a' && A[i]<='z') && !(A[i]>='0' && A[i]<='9')) //If the character is not a letter or a number, it is invalid
            return 0;
    }

    return 1; //String is valid
}

