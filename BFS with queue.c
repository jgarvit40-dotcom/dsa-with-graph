#include <stdio.h>

int graph[10][10];   // adjacency matrix
int visited[10];     // visited array

void BFS(int start, int n) {
    int queue[20];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;   // Enqueue start node

    while (front < rear) {   // While queue not empty
        int u = queue[front++];   // Dequeue
        printf("%d ", u);         // Visit node

        // Check all neighbors of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = 1;         // mark visited
                queue[rear++] = v;      // Enqueue neighbor
            }
        }
    }
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start, n);

    return 0;
}
