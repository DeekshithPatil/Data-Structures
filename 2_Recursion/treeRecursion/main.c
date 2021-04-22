#include <stdio.h>
#include <stdlib.h>

void fun(int n)
{
    if(n>0)
    {
        printf("%d ", n);
        fun(n-1);
        fun(n-1); // Function is calling itself more than once in the same iteration.
    }
}

int main()
{
   fun(3);
    return 0;
}
