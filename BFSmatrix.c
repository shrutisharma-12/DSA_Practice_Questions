#include <stdio.h>
int queue[10], front = 0, rear = -1;
int n, graph[10][10], visited[10];

void Bfs(int v)
{
    int i;
    queue[++rear] = v;
    visited[v] = 1;

    while (front <= rear)
    {
        v = queue[front++];
        printf("%d", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
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
    printf("\nBFS: ");
    Bfs(start);
    return 0;
}
