#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

void view()
{
    node *ptr = head;

    if (ptr == NULL)
    {
        printf("Empty linked list");
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void add_first()
{
    int data;
    printf("Enter data in first position: ");
    scanf("%d", &data);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void add_last()
{
    int data;
    printf("Enter data in last position: ");
    scanf("%d", &data);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    node *ptr = head;
    if (ptr == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
    }
    else
    {
        new_node->data = data;
        new_node->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void add_any()
{
    printf("Inserting node at any position\n");
    int key;
    printf("Where you want to insert new node: ");
    scanf("%d", &key);
    node *ptr = head;
    if (head == NULL)
    {
        add_first();
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                node *new_node;
                new_node = (node *)malloc(sizeof(node));
                new_node->data = data;
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
        }
        add_last();
    }
}

int main()
{
    add_last();
    add_last();
    view();
}