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


int main()
{
    int arr[] = { 7, 8, 9, 10, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    partition(arr, 0, 5);

    printf("Partitioned array: ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
