#include <stdio.h>

int a[20][20], n, i, j;
void bfs(int v) 
{
    int found = 0; // Flag to check if any node is reachable
    for (i = 1; i <=n; i++) 
    {
        if (a[v][i] == 1) 
        { // Directly connected nodes only
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("0"); // Print 0 if no nodes are reachable
    }
}
int main() 
{
    int v,k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter graph data in matrix form:\n");
    for (i = 1; i <=n; i++)
        for (j = 1; j <=n; j++)
            scanf("%d", &a[i][j]);
    for (k=1; k<=n; k++)
    {
        printf("Enter the starting node: ");
        scanf("%d", &v);
        printf("Nodes reachable from %d are: \n", v);
        bfs(v);
        printf("\n");
    }
    return 0;
}
