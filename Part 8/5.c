//postfix evaluation
#include<stdio.h>
#include<string.h>
#define MAX 100000

typedef struct
{
    double data[MAX];
    int top;
}Stack;
Stack s1;
int push(Stack *s, double);
int pop(Stack *s, double *);

int main()
{
    char str[MAX];
    int i=0;
    double val3;
    s1.top=-1;

    printf("Enter the postfix expression: ");
    scanf("%s", str);

    while (str[i]!='\0')
    {
        if (str[i]>='0' && str[i]<='9')
            push(&s1, (double)(str[i]-'0'));
        else
        {
            if (str[i]=='+')
            {
                double t1, t2;

                pop(&s1, &t1);
                pop(&s1, &t2);

                push(&s1, (t2+t1));
            }
            else if (str[i]=='-')
            {
                double t1, t2;

                pop(&s1, &t1);
                pop(&s1, &t2);

                push(&s1, (t2-t1));
            }
            else if (str[i]=='*')
            {
                double t1, t2;

                pop(&s1, &t1);
                pop(&s1, &t2);

                push(&s1, (t2*t1));
            } 
            else
            {
                    double t1, t2;

                    pop(&s1, &t1);
                    pop(&s1, &t2);

                    push(&s1, (t2/t1));
            }        
        }
        i++;
    }

    pop(&s1, &val3);
    printf("The postfix evaluation is %.2lf", val3);

    return 0;
}

int push(Stack *s, double val1)
{
        if (s->top==MAX-1)
        {
            return 1;
        }
        s->top++;
        s->data[s->top]=val1;
        return 0;
}

int pop(Stack *s, double *val1)
{
    if (s->top==-1)
    {
        return 1;
    }

    *val1=s->data[s->top];
    s->top--;
    return 0;
}
