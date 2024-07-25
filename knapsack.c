#include <stdio.h>
#include <stdlib.h>

// Struct to store item details
typedef struct {
    float weight;
    float value;
    float ratio; // value-to-weight ratio
} Item;

// Merge function for merge sort
void merge(Item items[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    Item L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = items[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = items[m + 1 + j];
    }

    // Merge the temporary arrays back into items[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].ratio >= R[j].ratio) {
            items[k] = L[i];
            i++;
        } else {
            items[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        items[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        items[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(Item items[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(items, l, m);
        mergeSort(items, m + 1, r);

        // Merge the sorted halves
        merge(items, l, m, r);
    }
}

// Function to perform the fractional knapsack algorithm
void GreedyFracKnapsack(float W, int n, Item items[]) {
    float x[n]; // Array to store the fraction of each item
    float tempW = W;
    float totalValue = 0.0;
    int i;

    // Initialize fractions to zero
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (items[i].weight > tempW) {
            break;
        }
        x[i] = 1.0;
        tempW -= items[i].weight;
        totalValue += items[i].value;
    }

    // If there is remaining capacity in the knapsack
    if (i < n) {
        x[i] = tempW / items[i].weight;
        totalValue += x[i] * items[i].value;
    }

    printf("The fractions of items in the knapsack are: \n");
    for (i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }

    printf("Total value in the knapsack: %.2f\n", totalValue);
}

int main() {
    int n; // Number of items
    float W; // Capacity of the knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n]; // Array to store items

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &W);

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%f", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%f", &items[i].value);
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Sort items by value-to-weight ratio using merge sort
    mergeSort(items, 0, n - 1);

    // Perform the fractional knapsack algorithm
    GreedyFracKnapsack(W, n, items);

    return 0;
}