#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* front = NULL;
NODE* rear = NULL;

int isEmpty() {
    return (front == NULL);
}

void addQueue(int ele) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = NULL;

    if (isEmpty()) {
        front = rear = newnode;
        newnode->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
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
    if (front == rear) {
        ele = front->data;
        free(front);
        front = rear = NULL;
    } else {
        ele = front->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return ele;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    NODE* temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int ele, ch;

    do {
        printf("\n1. Add\n2. Delete\n3. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                addQueue(ele);
                break;
            case 2:
                ele = deleteQueue();
                if (ele != -1)
                    printf("Deleted Element: %d\n", ele);
                break;
            case 3:
                display();
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
