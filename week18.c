#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left;   // first child
    struct Node *right;  // next sibling
};

// Create node
struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert subdirectory (child or sibling)
struct Node* insert(struct Node* root, char parent[], char child[]) {
    if (root == NULL) return NULL;

    if (strcmp(root->name, parent) == 0) {
        if (root->left == NULL) {
            root->left = createNode(child);  // first child
        } else {
            struct Node* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = createNode(child); // sibling
        }
        return root;
    }

    insert(root->left, parent, child);
    insert(root->right, parent, child);

    return root;
}

// Preorder
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%s ", root->name);
    preorder(root->left);
    preorder(root->right);
}

// Inorder
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%s ", root->name);
    inorder(root->right);
}

// Postorder
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->name);
}

// Main
int main() {
    struct Node* root = createNode("root");
    int choice;
    char parent[50], child[50];

    while (1) {
        printf("\n1. Insert Directory\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter parent directory: ");
                scanf("%s", parent);
                printf("Enter new directory: ");
                scanf("%s", child);
                insert(root, parent, child);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
