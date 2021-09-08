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

int CountNodes(struct Node *p)
{
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

int CountNodesRecursion(struct Node *p)
{
    int count = 0;

    if(p!=NULL)
    {
        count = CountNodesRecursion(p->next);
        return count + 1;
    }

    else
        return 0;
}

int main()
{

    int A[] = {3,5,7,9,11};
    create(A,5);
    int NodesCount;

    NodesCount = CountNodesRecursion(first);

    printf("\nNumber of nodes = %d \n",NodesCount);

    free(first);

    return 0;
}
