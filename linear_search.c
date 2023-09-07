#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 6, 8, 10, 16, 18, 21};
    int size = sizeof(arr) / sizeof(int);
    int result = linearSearch(arr, size, 16);

    if (result != -1)
        printf("The key is at index %d", result);
    else
        printf("The key is not found in this array");
}