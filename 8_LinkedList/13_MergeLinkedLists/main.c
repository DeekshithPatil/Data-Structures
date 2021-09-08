#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;

void create1(int A[],int n)
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

void create2(int A[],int n)
{
    int i;
    struct Node *t, *last; //t is for temp

    second = (struct Node *) malloc (sizeof(struct Node));

    second->data = A[0];
    second->next = NULL;
    last = second;

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

void Concat(struct Node *p,struct Node *q)
{
    third = p;

    while(p->next!=NULL)
    {
        p = p->next;
    }

    p->next = q;
}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;

    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next=NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;

        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p!=NULL)
    {
        last->next = p;

    }
    if(q)
    {
        last->next = q;
    }

}

int main()
{

    int A[] = {3,3,7,7,7};
    int B[] = {1,2,3,4,5,5,180,200};
    int x;

    create1(A,5);
    create2(B,8);

    Merge(first,second);

    printf("Concatinated\n");
    Display(third);
    printf("\n\n");

    free(first);
    free(second);

    return 0;
}
