#include <stdio.h>

int graph[10][10];   // adjacency matrix
int visited[10];     // visited array

// DFS using stack
void DFS_stack(int start, int n) {
    int stack[20];   // stack array
    int top = -1;    // top pointer

    stack[++top] = start;   // push start node

    while (top >= 0) {
        int u = stack[top--];   // pop top element

        if (!visited[u]) {
            printf("%d ", u);   // visit node
            visited[u] = 1;

            // push all neighbors in reverse order for correct traversal
            for (int v = n - 1; v >= 0; v--) {
                if (graph[u][v] == 1 && !visited[v]) {
                    stack[++top] = v;
                }
            }
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

    printf("DFS using stack starting from vertex 0: ");
    DFS_stack(0, n);

    return 0;
}
