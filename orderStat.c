#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
             i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high){
        int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex)
        return arr[pivotIndex];
    else if (k < pivotIndex)
        return quickselect(arr, low, pivotIndex - 1, k);
    else
        return quickselect(arr, pivotIndex + 1, high, k);
}
return -1;
}

int findKthSmallest(int arr[], int n, int k) {
    if (k < 1 || k > n) {
        printf("k is out of bounds of the array\n");
        return -1;
    }
    return quickselect(arr, 0, n - 1, k - 1);
}

float findMedian(int arr[],int n){
    if(n%2==0)
        return quickselect(arr,0,n-1,n/2);
    else
        return (quickselect(arr,0,n-1,n/2-1)+quickselect(arr,0,n-1,n/2))/2.0;
}

int main() {
    int arr[] = {12,3,5,719,1,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the number for position:");
    scanf("%d",&k);
    int result = findKthSmallest(arr, n, k);
    if (result != -1) {
        printf("The %d-th smallest element is %d\n", k, result);
    }

    printf("Median:%.1f\n",findMedian(arr,n));
    return 0;
}