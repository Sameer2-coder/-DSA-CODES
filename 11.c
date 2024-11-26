#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Array to track visited nodes

// Function to perform BFS
void bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    // Mark the start node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int cur = queue[front++];  // Dequeue the current node
        printf("%d ", cur);

        // Visit all the adjacent vertices of cur
        for (i = 0; i < n; i++) {
            if (adj[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;  // Enqueue unvisited adjacent node
            }
        }
    }
    printf("\n");
}

// Function to perform DFS (recursive)
void dfs(int v, int n) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    // Visit all adjacent vertices of v
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);  // Recursive DFS call
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // BFS
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) visited[i] = 0;  // Reset visited array
    bfs(start, n);

    // DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) visited[i] = 0;  // Reset visited array
    printf("DFS Traversal: ");
    dfs(start, n);
    printf("\n");

    return 0;
}
