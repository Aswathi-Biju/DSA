//Implement binary search trees by performing insertion, search and deletion of numbers using Linked list. 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* node = malloc(sizeof(struct Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

struct Node* insert(struct Node* root, int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}

struct Node* search(struct Node* root, int key){
    if(root==NULL || root->data==key)
        return root;

    if(key<root->data)
        return search(root->left,key);
    else if(key>root->data)
        return search(root->right,key);
}

struct Node* min(struct Node* root){
    if(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node* delete(struct Node* root, int key){
    if(root==NULL)
        return root;
    if(key<root->data){
        root->left = delete(root->left,key);
    }else if(key>root->data){
        root->right = delete(root->right,key);
    }else{
        if(root->left==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = min(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root=NULL;
    int val[7] = {50, 30, 20, 40, 70, 60, 80};
    for(int i=0; i<7; i++){
        root=insert(root,val[i]);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    int key=70;
    printf("\nSearching %d in BST: %s\n",key, search(root,key)?"found":"not found");
    root=delete(root,50);
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    return 0;
}