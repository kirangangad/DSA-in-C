#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} NODE;

NODE* front = NULL;
NODE* rear = NULL;

void init() {
    front = rear = NULL;
}

int isEmpty() {
    return (front == NULL);
}

void addQueue(int ele) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = ele;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Inserted: %d\n", ele);
}

int deleteQueue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int ele;
    NODE* temp = front;
    front = front->next;
    ele = temp->info;
    free(temp);
    return ele;
}

int main() {
    int ele, ch;
    init();

    do {
        printf("\n1. Add\n2. Delete\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                addQueue(ele);
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue Underflow\n");
                } else {
                    ele = deleteQueue();
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
