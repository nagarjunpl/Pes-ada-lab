#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array
int partition(int a[], int low, int high) 
{
    int pivot = a[low];
    int i = low + 1, j = high;
    int temp;

    while (i <= j) 
    {
        while (i <= high && a[i] <= pivot) 
        {
            i++;
        }
        while (a[j] > pivot) 
        {
            j--;
        }
        if (i < j) 
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap pivot with a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

// Quick Sort function
void quick_sort(int a[], int low, int high) 
{
    if (low < high) 
    {
        int mid = partition(a, low, high);
        quick_sort(a, low, mid - 1);
        quick_sort(a, mid + 1, high);
    }
}

// Main function
int main()
{
    int n, i;
    int a[100];
    clock_t start, end;
    double time_taken;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    srand(time(0));
    printf("The random numbers are:\n");
    for (i = 0; i < n; i++) 
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    // Measure sorting time
    start = clock();
    quick_sort(a, 0, n - 1);
    end = clock();

    // Print sorted array
    printf("The sorted numbers are:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Calculate and display execution time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
