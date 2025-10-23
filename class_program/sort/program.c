#include <stdio.h>

int binarySearch(int arr[], int size, int target, int *steps) {
    int low = 0, high = size - 1;
    (*steps)++; // Initialization

    while (low <= high) {
        (*steps)++; // Loop condition
        int mid = low + (high - low) / 2;
        (*steps)++; // Mid calculation

        if (arr[mid] == target) {
            (*steps)++; // Comparison
            return mid;
        } else if (arr[mid] < target) {
            (*steps)++; // Comparison
            low = mid + 1;
        } else {
            (*steps)++; // Comparison
            high = mid - 1;
        }
    }
    (*steps)++; // Loop exit
    return -1;
}

int main() {
    int size, target, steps = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements of the sorted array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target, &steps);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    int space = sizeof(int) * size + 4 * sizeof(int); // arr + size, target, steps, and result
    printf("Space complexity = %d bytes\n", space);
    printf("Time complexity = %d units\n", steps);

    return 0;
}
