#include <stdio.h>

int res[20];
int s[20];
int j = 0;

void dfs(int u, int n, int cost[10][10])
{
    int v;
    s[u] = 1;
    for (v = 0; v < n; v++)
    {
        if (cost[u][v] == 1 && s[v] == 0)
        {
            dfs(v, n, cost);
        }
    }
    res[j++] = u;
}
void depth_first_traversal(int n, int cost[10][10]) 
{
    int i;
    for (i = 0; i < n; i++)
        s[i] = 0;
    for (i = 0; i < n; i++)
        {
        if (s[i] == 0)
        {
            dfs(i, n, cost);
        }
    }
}
int main() 
{
    int i, j, n, cost[10][10];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &cost[i][j]);
        }
    }
    depth_first_traversal(n, cost);
    printf("\nThe topological sequence is:\n");
    for (i = n - 1; i >= 0; i--) 
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
