#include <stdio.h>

struct Pair
{
    int max;
    int min;
};

struct Pair findmaxMin(int arr[], int low, int high)
{
    struct Pair result;
    struct Pair left;
    struct Pair right;
    int mid;

    if (low == high)
    {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    mid = (low + high) / 2;
    left = findmaxMin(arr, low, mid);
    right = findmaxMin(arr, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;

    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}
int main()
{

    int arr[] = {6, 4, 26, 14, 33, 64, 46};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair result = findmaxMin(arr, 0, n - 1);

    printf("Maximum element is: %d\n", result.max);
    printf("Minimum element is: %d\n", result.min);

    return 0;
}