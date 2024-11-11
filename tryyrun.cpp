#include <iostream>
using namespace std;

#define MAX_NODES 100  // Max number of nodes in the graph

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
bool visited[MAX_NODES];         // Visited array

// Function to perform BFS traversal from a given start node
void bfs(int start, int n) {
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS traversal: ";
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        // Visit all unvisited neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Recursive function to perform DFS traversal from a given node
void dfs(int node, int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> edges;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    // Input edges
    cout << "Enter edges (u v) format:" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;  // For undirected graph
    }

    // Perform BFS
    cout << "Enter starting node for BFS: ";
    int bfs_start;
    cin >> bfs_start;
    for (int i = 0; i < n; i++) visited[i] = false; // Reset visited array
    bfs(bfs_start, n);

    // Perform DFS
    cout << "Enter starting node for DFS: ";
    int dfs_start;
    cin >> dfs_start;
    for (int i = 0; i < n; i++) visited[i] = false; // Reset visited array
    cout << "DFS traversal: ";
    dfs(dfs_start, n);
    cout << endl;

    return 0;
}
