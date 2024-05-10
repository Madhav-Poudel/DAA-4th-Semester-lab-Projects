#include <stdio.h>

int main(void) {
    int numbers[] = {2, 5, 1, 3, 7, 4};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    // Print unsorted array
    printf("Unsorted Array:");
    for (int i = 0; i < length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    // Insertion Sort
    for (int i = 1; i < length; i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }

    // Print sorted array
    printf("Sorted Array:");
    for (int i = 0; i < length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}
