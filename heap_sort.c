#include <stdio.h>
#include <conio.h>

void heapify(int a[], int n, int i) {
    int j, item;
    j = 2 * i + 1;
    item = a[i];
    while (j < n) {
        if (j + 1 < n && a[j] < a[j + 1]) {
            j = j + 1;
        }
        if (item >= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = item;
}

void adjust(int a[], int n, int i) {
    int j, item;
    j = 2 * i + 1;
    item = a[i];
    while (j < n) {
        if (j + 1 < n && a[j] < a[j + 1]) {
            j = j + 1;
        }
        if (item >= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = item;
}

void heapsort(int a[], int n) {
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (i = n - 1; i >= 1; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjust(a, i, 0);
    }
}
int main() {
    int a[20], n, i;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    printf("Enter elements to sort: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
