#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;

void create(int A[],int n)
{
    int i;
    struct Node *t, *last; //t is for temp

    first = (struct Node *) malloc (sizeof(struct Node));

    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++) //index starts from 1 as 0th element is already assigned
    {
        t = (struct Node *) malloc (sizeof(struct Node)); //create a new node
        t->data = A[i];
        t->next = NULL;

        last->next = t; //Append the newly created node to the existing last element

        last = t; //Last is updated to newly created notde
    }
}

int Max(struct Node *p)
{
    int max=INT_MIN;

    while(p!=NULL)
    {
        if(p->data > max)
            max = p->data;
        p  = p->next;
    }

    return max;
}

int MaxRecursion(struct Node *p)
{
    int x=0;

    if(p == NULL)
        return INT_MIN;
    else
    {
        x = MaxRecursion(p->next);

        if(x > p->data)
            return x;
        else
            return p->data;
    }

}

int main()
{

    int A[] = {3,5,7,9,11};
    create(A,5);
    int maxVal;

    maxVal= MaxRecursion(first);

    printf("\nMax Val = %d \n",maxVal);

    free(first);

    return 0;
}
