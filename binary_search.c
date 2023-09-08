#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int key;
    printf("Enter the key: ");
    scanf("%d", key);
    int arr[] = {2, 6, 8, 10, 16, 18, 21};
    int size = sizeof(arr) / sizeof(int);
    int result = binarySearch(arr, size, key);

    if (result != -1)
        printf("The key is at index %d", result);
    else
        printf("The key is not found in this array");
}