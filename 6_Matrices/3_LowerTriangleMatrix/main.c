#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j,int x)
{
    if(i>=j)
    {
        m->A[i * (i-1)/2 + j - 1] = x; //Row major mapping formula to access (i,j) element in matrix
    }
}

int Get(struct Matrix m, int i,int j)
{
    if(i>=j)
        return m.A[i * (i-1)/2 + j - 1]; //Row major mapping formula
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i,j;

    for(i=1;i<m.n;i++)
    {
        for(j=1;j<m.n;j++)
        {
            if(i>=j)
                printf("%d ",m.A[i * (i-1)/2 + j - 1]);
            else
                printf("0 ");

        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int x;
    printf("Enter Dimension: ");
    scanf("%d",&m.n);

    m.A = (int *) malloc(m.n * (m.n + 1)/2 * sizeof(int)); //Number of non zero elements in a lower triangle matrix is n * (n + 1)/2

    printf("\nEnter all elements:\n");

    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }

    printf("\n");

    Display(m);

    free(m.A);
    return 0;
}
