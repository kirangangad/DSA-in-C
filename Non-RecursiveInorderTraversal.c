#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef struct node {
    int info;
    struct node *left, *right;
} NODE;

typedef struct stack {
    NODE* data[MAX];
    int top;
} STACK;

void init(STACK *s) {
    s->top = -1;
}

int isFull(STACK *s) {
    return s->top == MAX - 1;
}

int isEmpty(STACK *s) {
    return s->top == -1;
}

void push(STACK *s, NODE* temp) {
    if (!isFull(s)) {
        s->data[++s->top] = temp;
    }
}

NODE* pop(STACK *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return NULL;
}

NODE* createBST(NODE* root) {
    int n, num;
    NODE *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (NODE*) malloc(sizeof(NODE));
        printf("Enter data: ");
        scanf("%d", &num);
        newnode->info = num;
        newnode->left = newnode->right = NULL;

        if (root == NULL) {
            root = newnode;
        } else {
            temp = root;
            while (1) {
                if (num < temp->info) {
                    if (temp->left == NULL) {
                        temp->left = newnode;
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = newnode;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }
    return root;
}

void nonRecursiveInorder(NODE* root) {
    STACK s;
    init(&s);
    NODE* temp = root;

    while (1) {
        while (temp != NULL) {
            push(&s, temp);
            temp = temp->left;
        }
        if (isEmpty(&s)) {
            break;
        }
        temp = pop(&s);
        printf("%d ", temp->info);
        temp = temp->right;
    }
}

void preorder(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main() {
    NODE* root = NULL;
    int ch;

    do {
        printf("\n1: Create BST\n2: Non-Recursive Inorder Traversal\n3: Preorder Traversal\n4: Postorder Traversal\n0: Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                root = createBST(root);
                break;
            case 2:
                printf("Non-Recursive Inorder Traversal: ");
                nonRecursiveInorder(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!");
        }
    } while (ch != 0);

    return 0;
}
