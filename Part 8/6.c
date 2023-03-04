//prefix evaluation
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
    int i, l;
    double val3;
    s1.top=-1;

    printf("Enter the prefix expression: ");
    scanf("%s", str);

    l=strlen(str);

    for (i=l-1; i>=0; i--)
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

                push(&s1, (t1+t2));
            }
            else if (str[i]=='-')
            {
                double t1, t2;

                pop(&s1, &t1);
                pop(&s1, &t2);

                push(&s1, (t1-t2));
            }
            else if (str[i]=='*')
            {
                double t1, t2;

                pop(&s1, &t1);
                pop(&s1, &t2);

                push(&s1, (t1*t2));
            } 
            else
            {
                    double t1, t2;

                    pop(&s1, &t1);
                    pop(&s1, &t2);

                    push(&s1, (t1/t2));
            }        
        }
    }

    pop(&s1, &val3);
    printf("The prefix evaluation is %.2lf", val3);

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