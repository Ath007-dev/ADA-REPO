#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int a[20], n, ch = 1;

    while (ch) {
        printf("\nEnter the number of elements to sort (max 20): ");
        scanf("%d", &n);

        if (n > 20 || n <= 0) {
            printf("Invalid number of elements.\n");
            continue;
        }

        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        clock_t start = clock();
        heapsort(a, n);
        clock_t end = clock();

        printf("Sorted list:\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]);

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken: %.6f seconds\n", time_taken);

        printf("Do you want to run again? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    }

    return 0;
}
