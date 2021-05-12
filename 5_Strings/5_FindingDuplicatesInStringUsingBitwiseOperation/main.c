#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "finding";
    int x = 1;
    int H= 0;

    for(int i=0;str[i]!='\0';i++)
    {
        x = 1;

        x = x << (str[i] - 'a');

        if(x & H)
            printf("%c ",str[i]);
        else
            H = H | x;
    }
    //printf("Hello world!\n");
    return 0;
}
