#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef struct {
    int n;                  // number of vertices
    int adj[MAXV][MAXV];    // adjacency matrix
} Graph;

// Initialize graph with n vertices
void initGraph(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g->adj[i][j] = 0;
}

// Add undirected edge u-v
void addEdge(Graph *g, int u, int v) {
    if (u < 0 || u >= g->n || v < 0 || v >= g->n) return;
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Display adjacency matrix
void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->n; i++) printf("%2d ", i);
    printf("\n");
    
    for (int i = 0; i < g->n; ++i) {
        printf("%2d ", i);
        for (int j = 0; j < g->n; ++j)
            printf("%2d ", g->adj[i][j]);
        printf("\n");
    }
}

// Display edges
void displayEdges(Graph *g) {
    printf("\nEdges:\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = i; j < g->n; j++) {
            if (g->adj[i][j] == 1) {
                printf("%d -- %d\n", i, j);
            }
        }
    }
}

// BFS from source s
void bfs(Graph *g, int s) {
    int visited[MAXV] = {0};
    int queue[MAXV];
    int front = 0, rear = 0;
    
    visited[s] = 1;
    queue[rear++] = s;
    
    printf("BFS starting at %d: ", s);
    
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        
        for (int v = 0; v < g->n; ++v) {
            if (g->adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

// DFS utility function
void dfsUtil(Graph *g, int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);
    
    for (int v = 0; v < g->n; ++v) {
        if (g->adj[u][v] && !visited[v]) {
            dfsUtil(g, v, visited);
        }
    }
}

// DFS from source s
void dfs(Graph *g, int s) {
    int visited[MAXV] = {0};
    printf("DFS starting at %d: ", s);
    dfsUtil(g, s, visited);
    printf("\n");
}

int main() {
    Graph g;
    
    printf("=== Graph BFS and DFS Implementation ===\n\n");
    
    // Sample graph creation and demonstration
    printf("--- Demo Mode ---\n");
    initGraph(&g, 5);
    
    printf("Creating graph with 5 vertices\n");
    printf("Adding edges:\n");
    addEdge(&g, 0, 1); printf("0 -- 1\n");
    addEdge(&g, 1, 2); printf("1 -- 2\n");
    addEdge(&g, 2, 3); printf("2 -- 3\n");
    addEdge(&g, 3, 0); printf("3 -- 0\n");
    addEdge(&g, 1, 3); printf("1 -- 3\n");
    
    displayGraph(&g);
    displayEdges(&g);
    
    printf("\n");
    bfs(&g, 0);
    dfs(&g, 0);
    
    // User input mode
    printf("\n--- Interactive Mode ---\n");
    int n, edges, u, v, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    Graph g2;
    initGraph(&g2, n);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(&g2, u, v);
    }
    
    displayGraph(&g2);
    displayEdges(&g2);
    
    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(&g2, start);
    
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    dfs(&g2, start);
    
    return 0;
}