#include <stdio.h>

#define INF 9999

int main()
{
    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    int distance[n], visited[n];

    for(int i = 0; i < n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n; count++)
    {
        int min = INF, next = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && distance[i] < min)
            {
                min = distance[i];
                next = i;
            }
        }

        if(next == -1)
            break;

        visited[next] = 1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && distance[next] + cost[next][i] < distance[i])
            {
                distance[i] = distance[next] + cost[next][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(int i = 0; i < n; i++)
    {
        if(distance[i] == INF)
            printf("Vertex %d : No Path\n", i);
        else
            printf("Vertex %d : %d\n", i, distance[i]);
    }

    return 0;
}