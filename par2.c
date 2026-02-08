#include<stdio.h>
int top=-1;
char stack[30];
void push(char c)
{
    top++;
    stack[top]=c;
}
char pop()
{
    return stack[top--];
}
void status()
{
    if(top==-1)
    printf("\nBalanced");
    else
    printf("\nUnbalanced");
}
int main()
{
    char str[40];
    printf("\nEnter expression");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            push(str[i]);
        }
        else if(str[i]==')'&& pop()!='(')
        {
            status();
            return 0;
        }
        else if(str[i]==']'&& pop()!='[')
        {
            status();
            return 0;
        }
        else if(str[i]=='}'&& pop()!='{')
        {
            status();
            return 0;
        }

    }
    status();
    return 0;
}