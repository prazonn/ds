#include <stdio.h>
#define N 5

typedef struct queue
{
    int a[N];
    int front, rear;
    int count;
} queue;

int isfull(queue *q)
{
    if (q->count == N)
    {
        return 1;
    }
    else
        return 0;
}
int isempty(queue *q)
{
    if (q->count == 0)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(queue *q, int data)
{
    if (isfull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->count++;

        q->rear = (q->rear + 1) % N;
        q->a[q->rear] = data;
    }
}
void dequeue(queue *q)
{
    int x;
    if (isempty(q))
    {
        printf("Queue is out of bounds\n");
    }
    else
    {
        q->count--;
        x = q->a[q->front];
        q->front = (q->front + 1) % N;
        printf("Deleted: %d\n", x);
    }
}

void display(queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element in the Queue are : \n");
        int i = q->front;
        while (1)
        {
            if (i == q->rear)
            {
                printf("%d ", q->a[i]);
                break;
            }

            printf("%d ", q->a[i]);
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;

    int ch, data;
    while (1)
    {
        printf("\t\t-----------\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
        scanf("%d", &ch);
        if (ch == 4)
        {
            return 0;
        }
        switch (ch)
        {
        case 1:
        {
            printf("Enter the Element: ");
            scanf("%d", &data);
            enqueue(&q, data);
        }
        break;
        case 2:
        {
            dequeue(&q);
        }
        break;
        case 3:
        {
            display(&q);
        }
        break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}