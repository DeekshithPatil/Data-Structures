#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack
{
    int size;
    int top;
    int *S;
};

void Stackcreate(struct Stack *st,int size)
{
    st->size = size;

    st->top = -1;
    st->S = (int *) malloc(st->size * sizeof(int));

}

void StackDisplay(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if(st->top == -1)
        printf("Stack underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top-index+1<0)
        printf("Invalid Index \n");

    x = st.S[st.top-index + 1];
}

int isEmptyStack(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top==st.size - 1?1:0; //return 1 is full
}

int stackTop(struct Stack st)
{
    if(!isEmptyStack(st))
        return st.S[st.top]; //return topmost element

    return -1;

}


#endif // STACK_H_INCLUDED
