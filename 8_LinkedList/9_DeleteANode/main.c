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

int CountNodes(struct Node *p) //used to check length of linked list
{
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if(index < 1 || index > CountNodes(p))
    {
        return -1;
    }

    if(index == 1) //first node
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q = p;
            p= p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            free(p);
            return x;
        }
    }
    return -1;
}

int main()
{

    int A[] = {3,5,7,9,11};
    create(A,5);
    int x;

    x = Delete(first,1);

    Display(first);

    free(first);

    return 0;
}
