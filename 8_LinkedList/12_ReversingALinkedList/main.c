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



void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
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

void Reverse1(struct Node *p) //Reversing elements by storing elements in an array
{
    int *A;
    struct Node *q=p;
    int i=0;

    A = (int *)malloc(sizeof(int)*CountNodes(p));

    while(q!=NULL)
    {
       A[i] = q->data;
       q = q->next;
       i++;
    }

    q = p;
    i--;

    while(q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

    free(A);

}

void Reverse2(struct Node *p) //Reverse Links
{
    struct Node *q = NULL, *r = NULL;

    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    first = q;
}

void Reverse3(struct Node *q,struct Node *p) //Reverse links using recursion
{
    if(p!=NULL)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{

    int A[] = {3,3,7,7,7};
    create(A,5);
    int x;

    Reverse3(NULL,first);

    Display(first);

    free(first);

    return 0;
}
