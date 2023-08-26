#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int a[], int l, int h, int key)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] > key)
        binarySearch(a, l, mid - 1, key);
    else
        binarySearch(a, mid + 1, h, key);
}

// int binarySearch(int a[], int n, int key)
// {
//     int low = 0, mid;
//     int high = n - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (a[mid] == key)
//         {
//             return mid;
//         }
//         else if (a[mid] > key)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// void bubbleSort(int a[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 swap(&a[j], &a[j + 1]);
//             }
//         }
//     }
// }

// void insertionSort(int a[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int value = a[i];
//         int hole = i;

//         while (hole > 0 && a[hole - 1] > value)
//         {
//             a[hole] = a[hole - 1];
//             hole--;
//         }
//         a[hole] = value;
//     }
// }

int main()
{
    // int arr[] = {5, 3, 1, 7, 6, 2};
    int arr[] = {1, 3, 6, 7, 20, 23, 27, 31, 40};
    int n = sizeof(arr) / sizeof(int);
    printf("%d", binarySearch(arr, 0, n - 1, 21));
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
}