#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void recdfs(int m[MAXSIZE][MAXSIZE], int n, int v) {
    static int visited[MAXSIZE] = {0};
    int w;
    
    visited[v] = 1;
    printf("%d ", v + 1); // Printing vertex number (1-indexed)
    
    for (w = 0; w < n; w++) {
        if (m[v][w] == 1 && visited[w] == 0) {
            recdfs(m, n, w);
        }
    }
}

void createmat(int m[MAXSIZE][MAXSIZE], int n) {
    int i, j;
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("Is there an edge between %d and %d (1 for Yes, 0 for No): ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            } else {
                m[i][j] = 0; // No self-loops
            }
        }
    }
}

void dispmat(int m[MAXSIZE][MAXSIZE], int n) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[MAXSIZE][MAXSIZE], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    createmat(m, n);
    dispmat(m, n);

    printf("DFS of the graph starting from vertex 1 is: ");
    recdfs(m, n, 0);

    return 0;
}
