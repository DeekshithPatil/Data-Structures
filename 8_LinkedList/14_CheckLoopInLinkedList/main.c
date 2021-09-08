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

int isLoop(struct Node *f)
{
    struct Node *p,*q; //q jumps twice, p jumps once
    p = q = f;
    do
    {
        p=p->next;
        q=q->next;

        if(q !=NULL)
            q = q->next;
    }while(p && q && p!=q);

    if(p == q)
    {
        return 1; //It is a loop
    }
    else
    {
        return 0; //Not a loop
    }
}

int main()
{
    struct Node *t1,*t2;

    int A[] = {3,3,7,7,7};
    create(A,5);

    //Uncomment the below lines (till if statement) to create a loop

   /* t1=first->next->next;
    t2=first->next->next->next->next; //t2 is pointing to last

    t2->next = t1; //from 5th node it is pointing to second
    */

    if(isLoop(first))
        printf("\nThere is a loop in Linked List\n");
    else
        printf("No Loop! :')");

    free(first);

    return 0;
}
