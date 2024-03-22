//Program 4
#include<stdio.h>
#include<conio.h>
char stack[10];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return(stack[top--]);
}
int stpri(char ch)
{
    switch(ch)
    {
        case '#':
        case '(': return 0;
        case '+':
        case '-': return 2;
        case '*':
        case '%':
        case '/': return 4;
        case '^': return 5;
    }
    return 0;
}
int inpri(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 6;
    }
    return 0;
}
void convert(char in[20],char post[20])
{
    int i,j=0;
    char ch;
    for(i=0;in[i]!='\0';i++)
    {
        ch=in[i];
        switch(ch)
        {
            case '(': push(ch);
                      break;
            case ')': while(stack[top]!='(')
                          post[j++]=pop();
                      pop();
                      break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^': while(stpri(stack[top])>inpri(ch))
                          post[j++]=pop();
                      push(ch);
                      break;
            default: post[j++]=ch;
        }
    }
    while(stack[top]!='#')
        post[j++]=pop();
    post[j]='\0';
}
int main()
{
    char infix[20],postfix[20];
    push('#');
    printf("Enter infix expression");
    fflush(stdin);
    gets(infix);
    convert(infix,postfix);
    printf("\n The postfix expression is:%s",postfix);
    return 0;
}
