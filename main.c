#include <stdio.h>

void change(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 42;
    int b = 13;
    printf("%d %d\n", a, b);
    change(&a, &b);
    printf("%d %d", a, b);
}