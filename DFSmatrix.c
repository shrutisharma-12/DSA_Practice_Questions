#include <stdio.h>
int n, graph[10][10], visited[10];

void Dfs(int v)
{
    int i;
    visited[v] = 1;
        printf("%d ", v);
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            Dfs(i);
            }
        }
    }
int main()
{
    int i, j, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS: ");
    Dfs(start);
    return 0;
}
