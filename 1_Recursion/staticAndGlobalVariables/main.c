#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1) + x; // Since X is static, it is initialised only once
        //even though the function is calling itself again and again, value of X is initialised
        //only during compilation in code section of memory
    }
    return 0;
}

int main()
{
    int r;
    r=fun(5);
    printf("%d\n", r);
    //after second function call, value of x becomes 10. Hence 50 is returned.
    r=fun(5);
    printf("%d", r);
    return 0;
}
