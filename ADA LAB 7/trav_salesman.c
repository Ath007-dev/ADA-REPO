#include <stdio.h>
#include <limits.h>

#define V 4

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[V];
int min_path = INT_MAX;

void tsp(int pos, int count, int cost, int start) {
    if (count == V && graph[pos][start]) {
        if (min_path > cost + graph[pos][start])
            min_path = cost + graph[pos][start];
        return;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            tsp(i, count + 1, cost + graph[pos][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    visited[0] = 1;
    tsp(0, 1, 0, 0);
    printf("Minimum cost Hamiltonian Cycle: %d\n", min_path);
    return 0;
}
