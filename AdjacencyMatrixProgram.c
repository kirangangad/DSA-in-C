#include <stdio.h>

void createMat(int m[10][10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = 0;
            if (i != j) {
                printf("Is there an edge between %d and %d? (1/0): ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
}

void dispMat(int m[10][10], int n) {
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
    int m[10][10], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of vertices. Please enter between 1 and 10.\n");
        return 0;
    }

    createMat(m, n);
    dispMat(m, n);

    return 0;
}
