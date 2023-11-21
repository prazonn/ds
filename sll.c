#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtStart(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtIndex(struct Node **head, int data, int index)
{
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        insertAtStart(head, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromStart(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtIndex(struct Node **head, int index)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        deleteFromStart(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtStart(&head, 5);
    insertAtIndex(&head, 7, 1);
    printList(head);

    deleteFromEnd(&head);
    deleteFromStart(&head);
    deleteAtIndex(&head, 69);
    insertAtEnd(&head, 29);
    insertAtStart(&head, 22);
    printList(head);

    return 0;
}
