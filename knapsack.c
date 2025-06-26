#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void knapsack(int n, int w[], int m, int V[10][10], int p[]) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + p[i]);
        }
    }
}

void main() {
    int m, n, i, j;
    int p[10], w[10];
    int V[10][10];

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of objects:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of objects:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    knapsack(n, w, m, V, p);

    printf("The output is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", V[i][j]);
        }
        printf("\n");
    }

    printf("Maximum profit is: %d\n", V[n][m]);
}
