#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n, visited[MAX];

struct Node
{
    int v;
    struct Node *next;
};

struct Node *adj[MAX];

void addEdge(int u, int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void Dfs(int v)
{
    struct Node *temp;

    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];
    while (temp != NULL)
    {
        if (visited[temp->v] == 0)
            Dfs(temp->v);
        temp = temp->next;
    }
}

int main()
{
    int i, x, start;

    for (i = 0; i < MAX; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of nodes (<=10): ");
    scanf("%d", &n);

    printf("\nEnter adjacency list for each node");
    printf("\n(enter -1 to stop for that node)\n");

    for (i = 0; i < n; i++)
    {
        printf("Neighbors of %d: ", i);
        while (1)
        {
            scanf("%d", &x);
            if (x == -1)
                break;
            addEdge(i, x);
            addEdge(x, i);
        }
    }

    printf("\nEnter starting node: ");
    scanf("%d", &start);

    printf("\nDFS: ");
    Dfs(start);

    return 0;
}
