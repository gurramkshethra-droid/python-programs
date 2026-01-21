#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[30];
int priority(char x) {
    if(x=='(' || x==')')
    return 0;
    else if(x=='*' || x=='/')
    return 2;
    else if(x=='+' || x=='-')
    return 1;
    return -1;
}
void push(char x) {
    top++;
    stack[top]=x;
}
char pop() {
    if(top==-1)
    return -1;
    else {
        return stack[top--];
    }

}
int main() {
    char in[20], x;
    int i;
    printf("\n enter the character");
    scanf("%s",in);
    for( i=0; in[i]!='\0'; i++) {
        if(isalnum(in[i]))
        printf("%c",in[i]);
        else if(in[i]=='(')
        push(in[i]);
        else if(in[i]==')') {
            while((x=pop())!='(')
            printf("%c",x);
        }  
        else {
            while(top!=-1 && (priority(stack[top])>=priority(in[i]))) {
                printf("%c", pop());
            }
            push(in[i]);
        }
    }
    while(top!=-1) {
        printf("%c",pop());
    }
    return 0;
}