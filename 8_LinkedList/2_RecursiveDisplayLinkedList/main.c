#include <stdio.h>
#include <stdlib.h>

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

void Display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Display(p->next);
    }

    else
        return;
}

void DisplayReverse(struct Node *p)
{
    if(p!=NULL)
    {
        DisplayReverse(p->next);
        printf("%d ",p->data);
    }

    else
        return;
}

int main()
{

    int A[] = {3,5,7,9,11};
    create(A,5);

    DisplayReverse(first);

    free(first);

    return 0;
}
