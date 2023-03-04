#include<stdio.h>
#define MAX 100000

typedef struct
{
    char data[MAX];
    int top;
}Stack;
Stack s1;
void infix_to_postfix(char *, char *);
int push(Stack *, char);
int pop(Stack *, char*);
int isoperand(char);
int isempty(Stack);
int isLH(char, char);
int getv(char );

int main()
{
    char infix[100000], output[100000];
    s1.top=-1;

    printf("Enter an infix expression: \n");
    scanf("%s", infix);

    infix_to_postfix(infix, output);

    printf("The equivalent postfix expression is: %s", output);

    return 0;
}

void infix_to_postfix(char *infix, char *output)
{
    int i=0, j=0;
    char t;

    while(infix[i]!='\0')
    {
        if (isoperand(infix[i]))
            output[j++]=infix[i];
        else if (infix[i]=='(')
            push(&s1, infix[i]);
        else if (infix[i]==')')
        {
            while(1)
            {
                pop(&s1, &t);
                if (t=='(')
                    break;
                output[j++]=t;
            }
        }
        else
        {
            if (isempty(s1))
                push(&s1, infix[i]);
            else
            {
                pop(&s1, &t);
                if (t=='(')
                {
                    push(&s1, '(');
                    push(&s1, infix[i]);
                }
                else
                {
                    if (isLH(t, infix[i]))
                    {
                        push(&s1, t);
                        push(&s1, infix[i]);
                    }
                    else
                    {
                        output[j++]=t;
                        i--;
                    }
                }
            } 
        }
        i++;
    }

    while ((pop(&s1, &t)==0))
        output[j++]=t;

    output[j]='\0';
}

int isoperand(char c)
{
    if ((c>='A' && c<='Z') || (c>='a' && c<='z'))
        return 1;
    else
        return 0;
}

int isempty(Stack s)
{
    if (s.top==-1)
        return 1;
    else
        return 0;
}

int isLH(char a, char b)
{
    if (getv(a)<getv(b))
        return 1;
    else
        return 0;
}

int getv(char d)
{
    int k;

    switch(d)
    {
        case '+':
        {
            k=1;
            return k;
        }
        case '-':
        {
            k=1;
            return k;
        }
        case '*':
        {
            k=2;
            return k;
        }
        case '/':
        {
            k=2;
            return k;
        }
        case '^':
        {
            k=3;
            return k;
        }
    }
}

int push(Stack *s, char val1)
{
        if (s->top==MAX-1)
        {
            return 1;
        }
        s->top++;
        s->data[s->top]=val1;
        return 0;
}

int pop(Stack *s, char *val1)
{
    if (s->top==-1)
    {
        return 1;
    }

    *val1=s->data[s->top];
    s->top--;
    return 0;
}