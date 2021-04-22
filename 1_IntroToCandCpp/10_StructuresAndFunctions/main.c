#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

void InitialiseStruct(struct Rectangle * r1,int l,int b)
{
    r1->length = l;
    r1->breadth = b;
}

int areaOfRectangle(struct Rectangle r)
{
    return(r.breadth * r.length);
}
int main()
{
    int area;
    struct Rectangle r1;

    InitialiseStruct(&r1,5,5);
    area = areaOfRectangle(r1);
    printf("Area = %d\n",area);
    return 0;
}
