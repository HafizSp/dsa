#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

// Print Linked List
void printList()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Add first
void addFirst(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Add Last
void addLast(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
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

// Add any position
void addAny(int key, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    node *ptr = head;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                newNode->data = value;
                newNode->next = ptr->next;
                ptr->next = newNode;
                return;
            }
            else
                ptr = ptr->next;
        }
    }
}

// delete first
void deleteFirst()
{
    if (head == NULL)
        return;
    head = head->next;
}

// delete last
void deleteLast()
{
    node *ptr = head;

    if (head == NULL)
    {
        return;
    }
    else if (ptr->next == NULL)
    {
        head = head->next;
        return;
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }
}

// delete any
void deleteAny(int value)
{
    node *ptr = head;
    if (head == NULL)
    {
        return;
    }
    if (ptr->data == value)
    {
        head = head->next;
        return;
    }
    while (ptr->next->data != value && ptr != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    if (ptr == NULL)
    {
        return;
    }
}

// Searching
void searching(int key)
{
    node *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Founded");
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    printf("Not found");
}

int main()
{

    addLast(99);
    addLast(79);
    addLast(2);
    searching(99);
    deleteAny(79);
    printList();
}