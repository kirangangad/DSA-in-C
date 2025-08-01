#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int rear, front;
} QUEUE;

void init(QUEUE *q) {
    q->rear = q->front = -1;
}

int isFull(QUEUE *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(QUEUE *q) {
    return (q->front == -1 || q->front > q->rear);
}

void addQueue(QUEUE *q, int ele) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    int i;
    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->data[q->rear] = ele;
    } else {
        for (i = q->rear; i >= q->front; i--) {
            if (q->data[i] > ele) {
                q->data[i + 1] = q->data[i];
            } else {
                break;
            }
        }
        q->data[i + 1] = ele;
        q->rear++;
    }
    printf("Inserted: %d\n", ele);
}

int deleteQueue(QUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int ele = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return ele;
}

void display(QUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    QUEUE q;
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
