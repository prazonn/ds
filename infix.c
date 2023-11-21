#include <stdio.h>
#include <string.h>
#define N 100

typedef struct stack
{
    char a[N];
    int top;
} stack;

int isfull(stack *s)
{
    if (s->top == N - 1)
        return 1;
    else
        return 0;
}

int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

char stacktop(stack *s)
{
    return (s->a[s->top]);
}

void push(stack *s, char data)
{
    if (isfull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->a[++(s->top)] = data; // Increment top before assigning
    }
}

char pop(stack *s)
{
    char x;
    if (isempty(s))
    {
        printf("Stack is empty\n");
        return '\0'; // Return a special character to indicate an error
    }
    else
    {
        x = stacktop(s);
        (s->top)--;
        return x;
    }
}

int priority(char x)
{
    if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '+' || x == '-')
    {
        return 2;
    }
    else
        return 1;
}

int isoperand(char x)
{
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        return 1;
    else
        return 0;
}

int isoperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    else
        return 0;
}

void intopost(char infix[], char postfix[])
{
    int i, j = 0; // Initialize j to 0
    stack s;
    s.top = -1;
    char c, element;

    for (int i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
        if (isoperand(c))
        {
            postfix[j++] = c;
        }
        else if (isoperator(c))
        {
            while (!isempty(&s) && priority(c) <= priority(stacktop(&s)))
            {
                element = pop(&s);
                postfix[j++] = element;
            }
            push(&s, c);
        }
        else if (c == '(')
        {
            push(&s, c);
        }
        else if (c == ')')
        {
            while (!isempty(&s) && stacktop(&s) != '(')
            {
                element = pop(&s);
                postfix[j++] = element;
            }
            if (!isempty(&s) && stacktop(&s) == '(')
            {
                pop(&s); // Pop the '('
            }
        }
    }
    while (!isempty(&s))
    {
        element = pop(&s);
        postfix[j++] = element;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[N], postfix[N];

    printf("Enter the Infix Expression\n");
    scanf("%s", infix);
    intopost(infix, postfix);
    puts(postfix);
    return 0;
}
