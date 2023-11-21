#include <stdio.h>

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int a[], int size)
{
    int i, j, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&a[i], &a[min]);
        }
    }
}
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main()
{
    int a[] = {23, 78, 45, 24, 2354, 94, 34, 52, 45, 64, 23, 12, 34, 32, 22, 82, 92, 24};

    int n = sizeof(a) / sizeof(a[0]);

    display(a, n);
    sort(a, n);
    display(a, n);
}