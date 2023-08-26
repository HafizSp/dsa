#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[iMin])
            {
                iMin = j;
            }
        }
        swap(&arr[i], &arr[iMin]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    printf("Array Before Sorting: ");
    printArray(arr, n);
    printf("\n");

    selectionSort(arr, n);
    printf("Array After Sorting: ");
    printArray(arr, n);
}
