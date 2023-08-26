#include <stdio.h>

void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++){
       printf("%d ", arr[i]);
   }
}

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n; i++){
       for (int j = 0; j < n - i - 1; j++){
           if (arr[j + 1] < arr[j]){
               swap(&arr[j], &arr[j + 1]);
           }
       }
   }
}

int main() {
   int arr[] = {5, 3, 4, 2, 1};
   int n = sizeof(arr) / sizeof(int);

   printf("Array Before Sorting: ");
   printArray(arr, n);
   printf("\n");

   bubbleSort(arr, n);
   printf("Array After Sorting: ");
   printArray(arr, n);
}
