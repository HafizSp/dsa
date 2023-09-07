#include <stdio.h>

void margeTwoArray(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < m)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }
}

void margeSingleArray(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    // Remaining first half element insert into array (b)
    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    // OR

    // Remaining element insert into array (b)
    while (j <= high)
    {
        b[k++] = a[j++];
    }

    // Copy all the element from array (b) to array (a)
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void recursiveMergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        recursiveMergeSort(arr, low, mid);
        recursiveMergeSort(arr, mid + 1, high);
        margeSingleArray(arr, low, mid, high);
    }
}

int main()
{
    // int arr[] = {9, 8, 7, 6, 4, 5, 3, 2};
    // int size = sizeof(arr) / sizeof(int);
    // int low = 0;
    // int high = size - 1;
    // printf("%d", high);

    // int a[] = {2, 10, 18, 20, 23};
    // int b[] = {4, 9, 19, 25};
    // int c[9];
    // marge(a, b, c, 5, 4);
    // printArray(c, 9);

    // int arr[] = {2, 5, 8, 12, 3, 6, 7, 10};
    // int size = sizeof(arr) / sizeof(int);
    // int low = 0, high = size - 1;
    // int mid = (low + high) / 2;
    // margeSingleArray(arr, low, mid, high);
    // printArray(arr, size);

    int arr[] = {9, 8, 7, 6, 4, 5, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    int low = 0, high = size - 1;
    recursiveMergeSort(arr, low, high);
    printArray(arr, size);
}