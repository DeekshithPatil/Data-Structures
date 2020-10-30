#include <stdio.h>
#include <stdlib.h>

double e(int x, int n)
{
    static double f=1, p=1;
    double r;

    if(n==0)
        return 1;
    else{
        r = e(x,n-1);
        p=p*x;
        f=f*n;
        return r + p/f;
    }
}

int main()
{
    printf("%lf ", e(4,30));
    return 0;
}
