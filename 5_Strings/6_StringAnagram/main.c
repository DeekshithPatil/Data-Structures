#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i] - 'a']++;
    }

    for(i=0;B[i]!='\0';i++)
    {
        H[B[i] - 'a']--;

        if((H[B[i] - 'a']) < 0)
        {
            printf("Not Anagram\n");
            break;
        }
    }

    if(B[i] == '\0')
        printf("Anagram\n");

    return 0;
}
