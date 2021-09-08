#include <stdio.h>
#include <stdlib.h>

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

void SortedInsert(struct Node *p, int x)
{
    struct Node *t,*q=NULL; //q is used to keep track of previous node, while p for current node

    t = (struct Node *) malloc (sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL) //i.e no nodes exist
        first = t;
    else
    {
        while(p && p->data<x)
        {
            q = p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{

    int A[] = {3,5,7,9,11};
    create(A,5);

    SortedInsert(first,55);

    Display(first);

    free(first);

    return 0;
}
