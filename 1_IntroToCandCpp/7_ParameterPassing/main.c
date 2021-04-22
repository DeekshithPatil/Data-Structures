#include <stdio.h>
#include <stdlib.h>

void swapByValue(int x, int y) //Call by Value
{
    int temp;
    temp = x;
    x=y;
    y=temp;
}

void swapByAddress(int *x, int *y) //Call by address
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

int swapBYReference(int &x, int &y)
{
    int temp;
    temp = x;
    x=y;
    y=temp;
}


int main()
{
    int a=1,b=2;

    swapByValue(a,b);
    printf("%d %d\n",a,b);

    swapByAddress(&a,&b);
    printf("%d %d\n",a,b);

    swapBYReference(a,b);
    printf("%d %d\n",a,b);

    return 0;
}
