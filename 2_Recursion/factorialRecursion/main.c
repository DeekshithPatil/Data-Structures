#include <stdio.h>
#include <stdlib.h>

int fact(n)
{
    if(n==0)
        return 1;
    if(n<0)
        return -1; //for negative numbers, factorial does not exist
    return fact(n-1)*n;
}

int main()
{
    int r;
    r=fact(-4);
    printf("%d ", r);
    return 0;
}
