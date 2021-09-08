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

void Insert(struct Node *p,int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > CountNodes(p))
    {
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}

int main()
{

    Insert(first,0,10);
    //Insert(first,8,10); //Invalid index

    Display(first);

    free(first);

    return 0;
}
