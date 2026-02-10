Adjacency Matrix: `int graph[MAXV][MAXV]`
  - 2D array where `graph[i][j]` represents the weight of edge from vertex `i` to vertex `j`
  - `INF` (INT_MAX) indicates no edge exists between vertices
  - Diagonal elements can be 0 or INF (vertex to itself)

-dist[]: Integer array storing shortest distance from source to each vertex
Initially all distances set to INF, except source (set to 0)
  
Boolean array tracking which vertices have been processed
  0 = not visited, 1 = visited


Functions Implemented
1. `void dijkstra(int n, int graph[MAXV][MAXV], int src)`
Purpose: Implements Dijkstra's algorithm to find shortest paths from source vertex to all other vertices.

Parameters:
- `n`: Number of vertices in the graph
- `graph`: Adjacency matrix representation
- `src`: Source vertex index

Algorithm:
1. Initialize all distances to INF except source (distance 0)
2. For each vertex:
   - Find unvisited vertex with minimum distance
   - Mark it as visited
   - Update distances of its adjacent vertices
3. Print final distances


main() Method Organization

1. Input:
   - Prompt user for number of vertices
   - Validate input (1 to MAXV)
   - Read adjacency matrix (user enters -1 for no edge)
   - Convert -1 and diagonal zeros to INF
   - Read source vertex and validate

2. Function call:
   - Call `dijkstra()` function with graph and source

3. Output Phase:
   - Display shortest distances from source to all vertices
   - Show "INF" for unreachable vertices

**Output**
Enter number of vertices: 3

Enter adjacency matrix (use -1 for no edge, positive weights for edges):
Provide 3 x 3 entries (row by row):
1 5 4 
7 6 3
9 8 2

Enter source vertex (0 to 2): 0

Vertex   Distance from Source 0
------   ---------------------
0                0
1                5
2                4