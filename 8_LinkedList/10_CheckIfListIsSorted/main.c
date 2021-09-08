#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

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
    while(p!=NULL) //Traverse the Linked list
    {
        printf("%d ",p->data); //Print data element of the node
        p = p->next; //Point to the next node
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;

    while(p!=NULL)
    {
        if(p->data < x)
        {
            return 0; //Not sorted
        }

        x = p->data;
        p = p->next;
    }

    return 1; //Loop completed, thus list is sorted
}

int main()
{

    int A[] = {3,5,7,22,11};
    create(A,5);
    int x;

    x = isSorted(first);

    if(x)
        printf("\nSorted\n");
    else
        printf("\nNot Sorted\n");

    free(first);

    return 0;
}
