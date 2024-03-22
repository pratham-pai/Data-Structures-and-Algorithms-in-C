//Program 5a
#include<stdio.h>
#include<ctype.h>
#include<math.h>
int top=-1;
int stack[20];
void push(int ele)
{
    stack[++top]=ele;
}
int pop()
{
    return (stack[top--]);
}
void eval(char post[20])
{
    char ch;
    int i,b,a;
    for(i=0;post[i]!='\0';i++)
    {
        ch=post[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            b=pop();
            a=pop();
            switch(ch)
            {
                case '+': push(a+b);
                          break;
                case '-': push(a-b);
                          break;
                case '*': push(a*b);
                          break;
                case '/': if(b==0)
                          {
                              printf("\n Divide by zero error");
                              exit(0);
                          }
                          push(a/b);
                          break;
                case '^': push(pow(a,b));
                          break;
                case '%': if(b==0)
                          {
                              printf("\n Divide by zero error");
                              exit(0);
                          }
                          push(a%b);
                          break;
                default: printf("\nInvalid operation");
            }
        }
    }
}
int main()
{
    char post[20];
    printf("\n enter the postfix expression:");
    fflush(stdin);
    gets(post);
    eval(post);
    printf("\n the evaluated answer is: %d",pop());
    return 0;
}
