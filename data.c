#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int studentId;
    float marks;
    char section;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

void addLast()
{
    node *newNode = (node *)malloc(sizeof(node));
    int id;
    float marks;
    char sec;
    scanf("%d %0.2f %c", &id, &marks, &sec);

    newNode->studentId = id;
    newNode->marks = marks;
    newNode->section = sec;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void deleteFirst()
{
    if (head == NULL)
        return;
    head = head->next;
}

void printList()
{
    node *ptr = head;
    printf("Linked List: ");
    while (ptr != NULL)
    {
        printf("%d %0.2f %c ", ptr->studentId, ptr->marks, ptr->section);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        addLast();
    }

    printList();
}