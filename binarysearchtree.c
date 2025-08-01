#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *left, *right;
} NODE;

NODE* createBST(NODE *root) {
    int i, n, num;
    NODE *temp, *newnode;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (NODE*) malloc(sizeof(NODE));
        newnode->left = newnode->right = NULL;

        printf("Enter data: ");
        scanf("%d", &num);
        newnode->info = num;

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

void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main() {
    NODE *root = NULL;
    root = createBST(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
