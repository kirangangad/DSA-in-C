#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int front, rear;
} CQUEUE;

void init(CQUEUE *q) {
    q->front = q->rear = -1;
}

int isFull(CQUEUE *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(CQUEUE *q) {
    return (q->front == -1);
}

void addQueue(CQUEUE *q, int ele) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) 
        q->front = q->rear = 0;
    else 
        q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = ele;
    printf("Inserted: %d\n", ele);
}

int deleteQueue(CQUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int ele = q->data[q->front];
    if (q->front == q->rear) 
        q->front = q->rear = -1;
    else 
        q->front = (q->front + 1) % MAX;
    return ele;
}

void display(CQUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CQUEUE q;
    int ele, ch;
    init(&q);

    do {
        printf("\n1. Add\n2. Delete\n3. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                addQueue(&q, ele);
                break;
            case 2:
                ele = deleteQueue(&q);
                if (ele != -1)
                    printf("Deleted Element: %d\n", ele);
                break;
            case 3:
                display(&q);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
