typedef struct {
    int n;                  // number of vertices
    int adj[MAXV][MAXV];    // adjacency matrix
} Graph;

n stores the no. of total vertices in the graph
adj[MAXV][MAXV]- array representing adjacency matrix
MAXV is set 100

Functions Implemented
1. void initGraph(Graph *g, int n)
Purpose: Initializes an empty graph with n vertices
Parameters:
g - Pointer to the Graph structure
Algorithm:
Set the number of vertices: g->n = n
Use nested loops to traverse the entire adjacency matrix
Initialize all cells to 0 (no edges initially)

Outer loop: i from 0 to n-1 (rows)
Inner loop: j from 0 to n-1 (columns)
Set g->adj[i][j] = 0

2. void addEdge(Graph *g, int u, int v)
Purpose: Adds an undirected edge between vertices u and v
Parameters:
g - Pointer to the Graph structure
u - First vertex (0-based indexing)
v - Second vertex (0-based indexing)
Algorithm:
Validate vertices: Check if u and v are within valid range [0, n-1]

If invalid, return without adding edge

Add edge in both directions (undirected graph):
Set g->adj[u][v] = 1 (edge from u to v)
Set g->adj[v][u] = 1 (edge from v to u)

3. void displayGraph(Graph *g)
Purpose:Displays the adjacency matrix representation of the graph
Parameters:
g - Pointer to the Graph structure
Algorithm:
- Print header row with vertex numbers (0 to n-1)
- For each row (vertex i):
   - Print row number (vertex i)
   - Print all values in that row (connections from i)
- Shows complete adjacency matrix in table format

4. void displayEdges(Graph *g)
Purpose: Lists all edges in the graph (avoids duplicates)
Parameters:
g - Pointer to the Graph structure

Algorithm:
1. Use nested loops to traverse upper triangle of matrix
   - Outer loop: i from 0 to n-1
   - Inner loop: j from i to n-1 (only upper triangle)
2. If adj[i][j] = 1, print edge "i -- j"
3. Upper triangle traversal avoids printing same edge twice

5. void bfs(Graph *g, int s)

Purpose: Performs Breadth-First Search traversal starting from vertex s (main requirement)
Parameters:
g - Pointer to the Graph structure
s - Starting vertex for BFS (0-based)

Algorithm:
Step 1: Initialize data structures
- visited[MAXV] - Array to track visited vertices (all 0 initially)
- queue[MAXV] - Array used as queue for BFS
- front = 0 - Points to front of queue
- rear = 0 - Points to rear of queue

Step 2: Mark source and enqueue
- Set visited[s] = 1 (mark source as visited)
- Add source to queue: queue[rear++] = s

Step 3: Process queue (main BFS loop)
- While queue is not empty (front < rear):
  1. Dequeue vertex: u = queue[front++]
  2. Print vertex u (visit it)
  3. For all vertices v from 0 to n-1:
     - Check if edge exists: g->adj[u][v]
     - Check if not visited: !visited[v]
     - If both true:
       - Mark v as visited: visited[v] = 1
       - Enqueue v: queue[rear++] = v


6. void dfsUtil(Graph *g, int u, int visited[])

Purpose: Recursive helper function for DFS traversal
Parameters:
g - Pointer to the Graph structure
u- Current vertex being visited
visited[] - Array tracking visited vertices

Algorithm:
1. Mark current vertex as visited: visited[u] = 1
2. Print current vertex (visit it)
3. For all vertices v from 0 to n-1:
   - Check if edge exists: g->adj[u][v]
   - Check if not visited: !visited[v]
   - If both true:
     - Recursively call dfsUtil(g, v, visited) (go deep!)

7. void dfs(Graph *g, int s)

Purpose: Performs Depth-First Search traversal starting from vertex s (main requirement)
Parameters:
g - Pointer to the Graph structure
s - Starting vertex for DFS (0-based)

Algorithm:
1. Initialize visited[MAXV] array to all zeros
2. Print message indicating DFS start
3. Call dfsUtil(g, s, visited) to perform recursive DFS
4. Print newline at end

main() Method Organization

1. Demo Mode (Automatic Example)
- Creates a graph with 5 vertices (0 to 4)
- Adds the following edges:
  - 0 -- 1
  - 1 -- 2
  - 2 -- 3
  - 3 -- 0
  - 1 -- 3
  - Vertex 4 remains isolated (no edges)
- Displays the adjacency matrix
- Displays the list of edges
- Performs BFS starting from vertex 0
- Performs DFS starting from vertex 0
- Demonstrates traversal from isolated vertex 4

2. Interactive Mode (User Input)
- Prompts user for number of vertices
- Prompts user for number of edges
- Accepts edge inputs (u v pairs)
- Displays the created graph (matrix and edge list)
- Asks user for starting vertex for BFS
- Performs BFS from user-specified vertex
- Asks user for starting vertex for DFS
- Performs DFS from user-specified vertex

**Output**
=== Graph BFS and DFS Implementation ===

--- Demo Mode ---
Creating graph with 5 vertices
Adding edges:
0 -- 1
1 -- 2
2 -- 3
3 -- 0
1 -- 3

Adjacency Matrix:
    0  1  2  3  4
 0  0  1  0  1  0
 1  1  0  1  1  0
 2  0  1  0  1  0
 3  1  1  1  0  0
 4  0  0  0  0  0

Edges:
0 -- 1
0 -- 3
1 -- 2
1 -- 3
2 -- 3

BFS starting at 0: 0 1 3 2
DFS starting at 0: 0 1 2 3

--- Interactive Mode ---
Enter number of vertices: 3
Enter number of edges: 4
Enter edges (u v):
Edge 1: 4 8
Edge 2: 1 3
Edge 3: 7 6
Edge 4: 2 0

Adjacency Matrix:
    0  1  2
 0  0  0  1
 1  0  0  0
 2  1  0  0

Edges:
0 -- 2

Enter starting vertex for BFS: 2
BFS starting at 2: 2 
Enter starting vertex for DFS: 4
DFS starting at 4: 4