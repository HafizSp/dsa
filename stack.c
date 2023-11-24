#include <stdio.h>
#define MAX 100
#include <stdlib.h>

// int stack[MAX];
// int top = -1;

// void push(int value)
// {
//     if (top >= MAX - 1)
//     {
//         printf("Overflow.....\n");
//         return;
//     }
//     else
//     {
//         stack[++top] = value;
//     }
// }

// void pop()
// {
//     if (top < 0)
//     {
//         printf("Underflow....\n");
//         return;
//     }
//     else
//     {
//         --top;
//     }
// }
// void print_stack()
// {
//     if (top < 0)
//     {
//         printf("No item in the stack\n");
//     }
//     else
//     {
//         for (int i = top; i >= 0; i--)
//         {
//             printf("%d ", stack[i]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     push(7);
//     push(10);
//     push(110);
//     push(220);
//     print_stack();
// }

struct node
{
    int data;
    struct node *next;
};
typedef struct node stack;
stack *head = NULL;

void push(int value)
{
    stack *ptr = head;
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    if (head == NULL)
    {
        head = new;
        new->data = value;
        new->next = NULL;
    }
    else
    {
        new->data = value;
        new->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void pop()
{
    stack *ptr = head;
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if (ptr->next == NULL)
    {
        printf("No item in the stack\n");
        head = NULL;
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

void print_stack()
{
    stack *ptr = head;
    printf("Stack: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{

    push(6);
    pop();
    print_stack();
}