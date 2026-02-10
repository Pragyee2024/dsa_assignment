#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAXV 100
#define INF INT_MAX

// Dijkstra's algorithm for shortest paths from source
void dijkstra(int n, int graph[MAXV][MAXV], int src) {
    int dist[MAXV];      // distance from source to each vertex
    int visited[MAXV] = {0};  // visited status
    
    // Initialize distances
    for (int i = 0; i < n; ++i) 
        dist[i] = INF;
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; ++count) {
        // Pick minimum distance vertex not yet visited
        int u = -1;
        int minDist = INF;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break; // remaining vertices unreachable
        visited[u] = 1;
        
        // Update distances of adjacent vertices
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print results
    printf("\nVertex   Distance from Source %d\n", src);
    printf("------   ---------------------\n");
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) 
            printf("%d \t\t INF\n", i);
        else 
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXV) {
        printf("Invalid input\n");
        return 1;
    }
    
    int graph[MAXV][MAXV];
    printf("\nEnter adjacency matrix (use -1 for no edge, positive weights for edges):\n");
    printf("Provide %d x %d entries (row by row):\n", n, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            scanf("%d", &w);
            if (w == -1 || (i == j && w == 0)) 
                graph[i][j] = INF;
            else 
                graph[i][j] = w;
        }
    }
    
    int src;
    printf("\nEnter source vertex (0 to %d): ", n-1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= n) {
        printf("Invalid source vertex\n");
        return 1;
    }
    
    dijkstra(n, graph, src);
    
    return 0;
}