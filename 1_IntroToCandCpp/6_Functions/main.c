#include <stdio.h>
#include <stdlib.h>

int add(int x, int y)
{
    return(x+y);
}

int main()
{
    int num1 = 10,num2 = 15,sum;

    sum = add(num1,num2);

    printf("%d\n",sum);
    return 0;
}
