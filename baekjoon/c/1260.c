#include <stdio.h>
#include <stdlib.h>

int N;
int *vertex;
int **edge;


void DFS(int V)
{
    int i;
    printf("%d ", V);
    vertex[V - 1] = 1;
    for (i = 0; i < N; i++)
    {
        if (edge[V - 1][i] && !vertex[i])
            DFS(i + 1);
    }
}

void BFS(int V)
{
    int i, next = 0, available = 0;
    for (i = 0; i < N; i++)
    {
        if (edge[V - 1][i] && !vertex[i])
            available = 1;
    }
    if (!available)
        return;
    vertex[V - 1] = 1;
    for (i = 0; i < N; i++)
    {
        if (edge[V - 1][i] && !vertex[i])
        {
            printf("%d ", i + 1);
            vertex[i] = 1;
        }
    }
    for (i = 0; i < N; i++)
    {
        if (edge[V - 1][i])
            BFS(i + 1);
    }
}

int main()
{
    int M, V, i, j, v1, v2;
    scanf("%d %d %d", &N, &M, &V);

    // Initialize
    vertex = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
        vertex[i] = 0;

    edge = (int **)malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++)
    {
        edge[i] = (int *)malloc(sizeof(int) * N);
        for (j = 0; j < N; j++)
            edge[i][j] = 0;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &v1, &v2);
        edge[v1 - 1][v2 - 1] = 1;
        edge[v2 - 1][v1 - 1] = 1;
    }

    DFS(V);
    printf("\n");

    for (i = 0; i < N; i++)
        vertex[i] = 0;
    printf("%d ", V);
    BFS(V);

    free(vertex);
    for (i = 0; i < N; i++)
        free(edge[i]);
    free(edge);
    return 0;
}