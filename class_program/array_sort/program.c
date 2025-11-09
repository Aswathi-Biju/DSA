#include <stdio.h>

int main() {
    int size, target, steps = 0, low = 0, high, result = -1;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    high = size - 1;

    printf("Enter %d elements of the sorted array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        steps++;  
        if (arr[mid] == target) {
            result = mid;
            break;
        }

        steps++;  
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    int space = sizeof(arr) + 6 * sizeof(int);
    printf("Space complexity = %d bytes\n", space);
    printf("Time complexity (approx) = %d steps\n", steps);

    return 0;
}
