#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole = hole - 1;
        }
        arr[hole] = value;
    }
}

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    printf("Array Before Sorting: ");
    printArray(arr, n);
    printf("\n");

    insertionSort(arr, n);
    printf("Array After Sorting: ");
    printArray(arr, n);
}
