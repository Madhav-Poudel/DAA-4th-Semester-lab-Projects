#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[low]);

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high){
        int index = partition(arr, low, high);

        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int main()
{
    int arr[] = { 7, 8, 9, 10, 1, 5 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, arr_size - 1);

    printf("Partitioned array: ");
    for (int k = 0; k < arr_size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
