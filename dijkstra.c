#include <stdio.h>
#include <stdlib.h>

int cost[10][10], d[10], p[10], n;

void dij(int source, int dest)
{
    int i, j, u, v, min, s[10];
    for (i = 0; i < n; i++)
    {
        d[i] = cost[source][i];
        s[i] = 0;
        p[i] = source;
    }

    s[source] = 1;
    for (i = 1; i < n; i++)
    {
        min = 9999;
        u = -1;
        for (j = 0; j < n; j++)
        {
            if (d[j] < min && s[j] == 0)
            {
                min = d[j];
                u = j;
            }
        }

        if (u == -1)
            return;

        s[u] = 1;
        if (u == dest)
            return;

        for (v = 0; v < n; v++)
        {
            if (d[u] + cost[u][v] < d[v] && s[v] == 0)
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }
}

void print_path(int source)
{
    int destination, i;
    for (destination = 0; destination < n; destination++)
    {
        dij(source, destination);
        if (d[destination] != 999)
        {
            printf("The shortest path from source to every other vertex are:\n");
            i = destination;
            while (i != source)
            {
                printf("%d <-- ", i);
                i = p[i];
            }
            printf("%d = %d\n", i, d[destination]);
        }
    }
}

int main()
{
    int i, j, source;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex:");
    scanf("%d", &source);
    print_path(source);
}
