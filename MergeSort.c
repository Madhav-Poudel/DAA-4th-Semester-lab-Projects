#include <stdio.h>

void merge(int arr[], int l, int m, int r, int lvl) {

    for(int i = 1; i <= lvl; i ++) {
        printf("    ");
    }
    // printf("Divided: [ ");G
    // for(int i = l; i < r; i ++) {
    //     printf("%d, ", arr[i]);
    // }
    // printf("%d ]\n", arr[r]);
    printf("Merging: [ ");
    for(int i = 0; i < m - l + 1; i ++) {
        printf("%d, ", arr[l + i]);
    }
    printf(" ]");

    printf(" & [ ");
    for(int i = 0; i < r - m; i ++) {
        printf("%d, ", arr[m + 1 + i]);
    }
    printf(" ]\n");
    

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // printf("n1 = %d & n2 = %d\n", n1, n2);

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int lvl) {
    for(int i = 1; i <= lvl; i ++) {
        printf("    ");
    }
    printf("Divided: [ ");
    for(int i = l; i < r; i ++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n", arr[r]);
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, lvl + 1);
        mergeSort(arr, m + 1, r, lvl + 1);
        merge(arr, l, m, r, lvl + 1);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 7, 2, 5, 1, 9, 8, 6, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1, 1);
    printf("\nSorted array in Descending Order: ");
    printArray(arr, arr_size);
    return 0;
}