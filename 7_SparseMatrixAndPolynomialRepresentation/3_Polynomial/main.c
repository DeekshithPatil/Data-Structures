#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int  n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter the number of terms: \n");
    scanf("%d",&p->n);

    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter terms:\n");

    for(int i=0;i<p->n;i++)
    {
        scanf("%d %d",&p->terms[i].coeff,&p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        if(i == p.n - 1) //Last term does not have to display +
            printf("%dx%d",p.terms[i].coeff,p.terms[i].exp);
        else
            printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
    }
    printf("\n");
}

struct Poly * add(struct Poly *p1,struct Poly *p2)
{
    struct Poly *sum;
    int i,j,k;
    i=j=k=0;

    sum =(struct Poly *)malloc(sizeof(struct Poly));
    sum->terms=(struct Term *)malloc((p1->n + p2->n)*sizeof(struct Term));

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp > p2->terms[j].exp) //exponent of p1 is greater
        {
            sum->terms[k++]=p1->terms[i++];
        }
        else if(p1->terms[i].exp < p2->terms[j].exp) //exponent of p2 is greater
        {
            sum->terms[k++]=p2->terms[j++];
        }
        else //Both are equal. Add coefficients, exponent should be same
        {
           sum->terms[k].exp = p1->terms[i].exp;
           sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    //copy the remaining elements
    for(;i<p1->n;i++)
        sum->terms[k++] = p1->terms[i];

    for(;j<p2->n;j++)
        sum->terms[k++] = p2->terms[j];
    sum->n = k;

    return sum;
}

int main()
{
    struct Poly p1,p2,*p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1,&p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    free(p1.terms);
    free(p2.terms);
    free(p3->terms);
    free(p3);
    return 0;
}