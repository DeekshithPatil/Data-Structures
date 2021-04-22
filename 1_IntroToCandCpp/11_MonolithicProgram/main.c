#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length = 0,breadth = 0;
    printf("Enter length and breadth: \n");
    scanf("%d %d",&length,&breadth);

    printf("\nArea = %d, Perimeter=%d\n",length * breadth,(2 * (length + breadth)));

    return 0;
}
