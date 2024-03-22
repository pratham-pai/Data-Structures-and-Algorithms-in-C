#include<stdio.h>
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
    int i,a,b;
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
                case '/': if (b==0)
                          {
                              printf("Divide by 0");
                              exit(1);
                          }
                          push(a/b);
                          break;
                case '$': push(pow(a,b));
                          break;
                default : printf("Invalid operator");
                          exit(1);
            }
        }
    }
}

void main()
{
    char post[20];
    printf("Enter the Postfix expression: ");
    gets(post);
    eval(post);
    printf("The value is %d",pop());
}
