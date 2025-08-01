#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef struct {
    int data[MAXSIZE];
    int front, rear;
} QUEUE;

void init(QUEUE *s) {
    s->front = s->rear = -1;
}

void addq(QUEUE *s, int num) {
    if (s->rear == MAXSIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    s->data[++s->rear] = num;
}

int deleteq(QUEUE *s) {
    if (s->front == s->rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return s->data[++s->front];
}

int isempty(QUEUE *s) {
    return (s->rear == s->front);
}

void bfs(int m[10][10], int n) {
    int v, w;
    int visited[MAXSIZE] = {0};  // Ensure MAXSIZE is used
    QUEUE q;
    
    init(&q);
    v = 0;  // Starting vertex
    visited[v] = 1;
    addq(&q, v);

    printf("BFS Traversal: ");
    
    while (!isempty(&q)) {
        v = deleteq(&q);
        printf("v%d ", v + 1);

        for (w = 0; w < n; w++) {
            if (m[v][w] == 1 && visited[w] == 0) {
                addq(&q, w);
                visited[w] = 1;
            }
        }
    }
    printf("\n");
}

void createmat(int m[10][10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = 0;
            if (i != j) {
                printf("\nIs there an edge between %d and %d? (1/0): ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
}

void dispmat(int m[10][10], int n) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[10][10], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createmat(m, n);
    dispmat(m, n);
    bfs(m, n);

    return 0;
}
