#include<stdio.h>
#include<ctype.h>
int top=-1;
int stack[30];
void push(int x) {
    top++;
    stack[top]=x;
}
int pop () {
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int main() {
    char in[20],x;
    int i,num1, num2, v;
    printf("enter the expression");
    scanf("%s",in);
    for(i=0; in[i]!='\0'; i++) {
        if(isalpha(in[i])) {
            printf("\n enter the value for the digit %c",in[i]);
            scanf("%d",&v);
            push(v);
        }
        else if(isdigit(in[i])) {
            push(in[i]-'0');
        }
        else {
            num2=pop();
            num1=pop();
            switch(in[i])
            {
                case '+': push(num1+num2);
                break;
                case '-': push(num1-num2);
                break;
                case '*': push(num1*num2);
                break;
                case '/': push(num1/num2);
                break;
                default: printf("\nenter correct expression");
                break;
            }
        }
    }
    printf("the result is %d",stack[top]);
    return 0;
}