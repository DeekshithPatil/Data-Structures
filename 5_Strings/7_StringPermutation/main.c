#include <stdio.h>
#include <stdlib.h>

void permutate(char str[]);

int main()
{
    char s[] = "ABC";
    permutate(s);
    return 0;
}


void permutate(char str[])
{
    static int mem[6] = {0};
    static char res[6];
    int index;
    static int level=0;

    if(str[level] == '\0')
    {
        res[level] = '\0';
        printf("%s\n",res);
        return;
    }

    for(index=0;index<str[index]!='\0';index++)
    {
        if(mem[index] == 0)
        {
            res[level] = str[index];
            mem[index] = 1;
            level++;
            permutate(str);
            level--;
            mem[index] = 0;
        }
    }
}
