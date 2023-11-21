#include <stdio.h>
#define N 5

typedef struct queue
{
    int a[N];
    int front, rear;
} queue;

int isempty(queue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void inLeft(queue *q, int data)
{
    if (q->front == -1)
    {
        printf("FRONT FULL\n");
    }
    else
    {
        q->a[q->front] = data;
        q->front--;
    }
}
void inRight(queue *q, int data)
{
    if (q->rear == N - 1)
    {
        printf("REAR FULL\n");
    }
    else
    {
        q->rear++;
        q->a[q->rear] = data;
    }
}
void delLeft(queue *q)
{
    int x;
    if (isempty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        q->front++;
        x = q->a[q->front];
        printf("Deleted: %d", x);
    }
}
void delRight(queue *q)
{
    int x;
    if (isempty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        x = q->a[q->rear];
        q->rear--;

        printf("Deleted: %d", x);
    }
}

void display(queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

int main()
{
    queue q;
    q.front = q.rear = N / 2;
    int ch, data;
    while (1)
    {
        printf("1.InsertLeft\n2.InsertRight\n3.DeleteLeft\n4.DeleteRight\n5.Display\n0.Exit\n\n");
        scanf("%d", &ch);
        if (ch == 0)
            return 0;
        switch (ch)
        {
        case 1:
            printf("Element From Front:  ");
            scanf("%d", &data);
            inLeft(&q, data);
            break;
        case 2:
            printf("Element From Rear:  ");
            scanf("%d", &data);
            inRight(&q, data);
            break;
        case 3:
            delLeft(&q);
            break;
        case 4:
            delRight(&q);
            break;
        case 5:
            display(&q);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}