#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 6
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V] = {false};
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}
int main() {
    int graph[V][V] = {
        {0, 5, 12, 0, 0, 0},
        {5, 0, 3, 4, 0, 0},
        {12, 3, 0, 1, 8, 0},
        {0, 4, 1, 0, 2, 7},
        {0, 0, 8, 2, 0, 5},
        {0, 0, 0, 7, 5, 0}
    };
    dijkstra(graph, 0);
    return 0;
}