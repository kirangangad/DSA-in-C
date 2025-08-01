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
    return (q->front == q->rear);
}

void addQueue(QUEUE *q, int ele) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = ele;
    printf("Inserted: %d\n", ele);
}

int deleteQueue(QUEUE *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    q->front++;
    return q->data[q->front];
}

int main() {
    QUEUE q;
    int ele, ch;
    init(&q);

    do {
        printf("\n1. Add\n2. Delete\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (isFull(&q))
                    printf("Queue Overflow\n");
                else {
                    printf("Enter element: ");
                    scanf("%d", &ele);
                    addQueue(&q, ele);
                }
                break;
            case 2:
                if (isEmpty(&q))
                    printf("Queue Underflow\n");
                else {
                    ele = deleteQueue(&q);
                    printf("Deleted Element: %d\n", ele);
                }
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
