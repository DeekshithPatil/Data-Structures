#include <stdio.h>
#include <stdlib.h>

int area(int length,int breadth)
{
    return length * breadth;
}

int perimeter(int length,int breadth)
{
    return(2 * (length * breadth));
}

int main()
{
    int length = 2,breadth = 4;

    printf("%d %d\n",area(length,breadth),perimeter(length,breadth));
    return 0;
}
