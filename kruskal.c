#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int cost[10][10];
int find(int node, int parent[10]) {
    while (parent[node] != node)
        node = parent[node];
    return node;
}

int union_ij(int i, int j, int parent[10]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal_mst() {
    int count = 0, i, j, k, u, v;
    int parent[10], min, sum = 0, n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (min == 999)
            break;

        i = find(u, parent);
        j = find(v, parent);

        if (i != j) {
            printf("\nEdge %d: (%d -> %d) cost = %d", count + 1, u, v, min);
            union_ij(i, j, parent);
            sum += min;
            count++;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    if (count == n - 1) {
        printf("\n\nMinimum cost spanning tree exists.");
        printf("\nCost of MST = %d", sum);
    } else {
        printf("\nMinimum spanning tree does not exist.");
    }
}

int main() {
    printf("Kruskal's Algorithm Implementation\n");
    kruskal_mst();
    getch();
    return 0;
}
