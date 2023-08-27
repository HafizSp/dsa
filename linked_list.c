#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

void print_linked_list()
{
    node *ptr = head;
    printf("Linked List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_first_position()
{
    int data;
    printf("Enter the data item: ");
    scanf("%d", &data);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_last_position()
{
    node *ptr = head;
    int data;
    printf("Enter the last item: ");
    scanf("%d", &data);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    if (head == NULL)
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

void insert_any_position()
{
    printf("Inserting node at any position\n");
    int key;
    printf("Where you want to insert new node: ");
    scanf("%d", &key);
    node *ptr = head;
    if (head == NULL)
    {
        printf("No node in linked list\n");
        insert_first_position();
        return;
    }
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            node *new_node;
            new_node = (node *)malloc(sizeof(node));
            int data;
            printf("Enter the item: ");
            scanf("%d", &data);
            new_node->data = data;
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    insert_last_position();
}

int main()
{
    insert_first_position();
    insert_first_position();
    print_linked_list();

    insert_last_position();
    insert_any_position();
    print_linked_list();
}