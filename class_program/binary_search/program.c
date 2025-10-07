#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) root->left = delete(root->left, data);
    else if (data > root->data) root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    
    while(1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display Inorder\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) 
                    printf("Node %d found.\n", value);
                else
                    printf("Node %d not found.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                return 0; 
            
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
