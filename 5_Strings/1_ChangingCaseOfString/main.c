#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[] = "wElCoMe";
    int i;
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i]>= 65 && arr[i]<=90) //The character is in upper case
            arr[i]+=32;

        else if(arr[i]>= 'a' && arr[i]<='z') //The character is in lower case
            arr[i]-=32;
    }
    printf("%s\n",arr);
    return 0;
}
