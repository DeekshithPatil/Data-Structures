#include <stdio.h>
#include <stdlib.h>

int C(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    else
        return C(n-1,r-1) + C(n-1,r);
}

int main()
{
    int result;
    result = C(5,2);
    printf("%d ", result);
    return 0;
}
