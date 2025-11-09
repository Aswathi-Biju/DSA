#include <stdio.h>

long long steps;

void bubbleSort(int arr[], int n) {
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                steps++;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            steps++;
        }
        arr[j + 1] = key;
        steps++;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        steps++;
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            steps++;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    steps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        steps++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void copy(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, ch;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Compare All\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                copy(arr, temp, n);
                bubbleSort(temp, n);
                printf("Sorted: "); print(temp, n);
                printf("Steps: %lld\n", steps);
                break;

            case 2:
                copy(arr, temp, n);
                insertionSort(temp, n);
                printf("Sorted: "); print(temp, n);
                printf("Steps: %lld\n", steps);
                break;

            case 3:
                copy(arr, temp, n);
                steps = 0;
                quickSort(temp, 0, n - 1);
                printf("Sorted: "); print(temp, n);
                printf("Steps: %lld\n", steps);
                break;

            case 4:
                copy(arr, temp, n);
                steps = 0;
                mergeSort(temp, 0, n - 1);
                printf("Sorted: "); print(temp, n);
                printf("Steps: %lld\n", steps);
                break;

            case 5: {
                long long s1, s2, s3, s4;

                copy(arr, temp, n); bubbleSort(temp, n); s1 = steps;
                copy(arr, temp, n); insertionSort(temp, n); s2 = steps;
                copy(arr, temp, n); steps = 0; quickSort(temp, 0, n - 1); s3 = steps;
                copy(arr, temp, n); steps = 0; mergeSort(temp, 0, n - 1); s4 = steps;

                printf("\n--- Step Comparison ---\n");
                printf("Bubble Sort   : %lld\n", s1);
                printf("Insertion Sort: %lld\n", s2);
                printf("Quick Sort    : %lld\n", s3);
                printf("Merge Sort    : %lld\n", s4);
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
