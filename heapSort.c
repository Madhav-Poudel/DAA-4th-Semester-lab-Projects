#include <stdio.h>

// Heapify function
void heapify(int arr[], int n, int i)
{
	int temp, maximum, left, right;
	maximum = i;
	right= 2 * i + 2;
	left = 2 * i + 1;

	if (left < n && arr[left] > arr[maximum])
		maximum = left;

	if (right < n && arr[right] > arr[maximum])
		maximum = right;

	if (maximum != i) {
		temp = arr[i];
		arr[i] = arr[maximum];
		arr[maximum] = temp;
		heapify(arr, n, maximum);
	}
}

// HeapSorting function
void heapsort(int arr[], int n)
{
	int i, temp;
	for (i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (i = n - 1; i > 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[] = {11,12,15,13,5,6,7 };
	int n = 6;

	printf("Original Array : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	heapsort(arr, n);

	printf("Array after performing heap sort: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}