#include <stdio.h>
#define N 10

// use structure to create a stack using array

typedef struct stack
{
    int a[N];
    int top;
} stack;

// isfull when top = N-1

int isfull(stack *s)
{
    if (s->top == N - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isempty when top =-1
int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// push till isfull

void push(stack *s, int data)
{
    if (isfull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = data;
    }
}

// pop till isempty
// return type depends on requirement of program

void pop(stack *s)
{
    int x;
    if (isempty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        x = s->a[s->top];
        s->top--;
        printf("%d Deleted\n", x);
    }
}
// the following function can be used in pop function instead of s->a[s->top], but to avoid confusion we have kept it simple.
int stacktop(stack *s)
{
    if (isempty(s))
    {
        printf("stack is empty\n");
    }
    else

        return s->a[s->top];
}

// displaying stack from top to bottom
void display(stack *s)
{
    int i;
    if (isempty(s))
    {
        printf("Stack is empty");
    }
    else
    {

        for (i = s->top; i > -1; i--)
        {
            printf("%d ", s->a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch, data;
    // initializing stack here
    stack s;
    s.top = -1;

    while (1)
    {
        printf("1.Push\n2.Pop\n3.Stack Top\n4.Display\n5.Exit\n");
        scanf("%d", &ch);
        if (ch == 5)
        {
            break; // will break the while loop
        }
        switch (ch)
        {
        case 1:
            printf("Enter the Element: ");
            scanf("%d", &data);
            push(&s, data);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            data = stacktop(&s);
            printf("%d is at the top\n", data);

            break;
        case 4:
            printf("Element in Stack\n");
            display(&s);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}
