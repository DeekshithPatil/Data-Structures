#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n; //To hold dimensions M x N
    int num; //To hold the number of non-zero elements
    struct Element *e;
};

void create(struct Sparse *s)
{
    printf("Enter dimensions m and n: \n");
    scanf("%d %d",&s->m,&s->n);

    printf("Enter total number of non-zero elements:\n");
    scanf("%d",&s->num);

    s->e = (struct Element *) malloc (s->num * sizeof(struct Element));

    printf("Enter all non-zero elements: \n");

    for(int i=0;i<s->num;i++)
    {
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }

}

void Display(struct Sparse s)
{
    int i,j,k=0;

    printf("\n");

    for(i=0;i<s.m;i++)
    {
        for(j=0; j< s.n; j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                printf("%d ",s.e[k].x);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;

    create(&s);
    Display(s);

    free(s.e);

    return 0;
}
