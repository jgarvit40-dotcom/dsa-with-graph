#include <stdio.h>

int graph[10][10];   // adjacency matrix
int visited[10];     // visited array to track nodes

// DFS function
void DFS(int u, int n) {
    printf("%d ", u);   // print current node
    visited[u] = 1;     // mark as visited

    // check all adjacent vertices
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && visited[v] == 0) {
            DFS(v, n);  // recursive call for unvisited neighbor
        }
    }
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("DFS Traversal starting from vertex 0: ");
    DFS(0, n);

    return 0;
}
