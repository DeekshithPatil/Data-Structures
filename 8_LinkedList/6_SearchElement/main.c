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

struct Node * search(struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * searchRecursion(struct Node *p, int key)
{
    int x = 0;

    if(p == NULL)
        return NULL;
    else
    {
        if(p->data == key)
            return p;
        else
            return searchRecursion(p->next,key);
    }
}

struct Node * headSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while(p!=NULL)
    {
        if(p->data == key) //Make the node in which key is present as the first
        {
            q->next = p->next;

            p->next = first;

            first = p;

            return p;
        }

        q= p;
        p = p->next;
    }

    return p;
}

int main()
{

    int A[] = {3,5,7,9,11};

    create(A,5);

    struct Node *p;

    p= headSearch(first,7);

    if(p)
        printf("\nAddress = %u, value = %d\n",p,p->data);
    else
        printf("\nKey not found\n");

    free(first);

    return 0;
}
