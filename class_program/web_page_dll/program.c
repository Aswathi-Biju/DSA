#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char url[50];           
    struct node* prev;      
    struct node* next;      
};
struct node *head, *tail, *newnode, *current;


void visit(char* url){
    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newnode->url, url);
    newnode->prev = current;
    if (current != NULL) {
        current->next = newnode;
    }
    newnode->next = NULL;
    current = newnode;
    printf("Visited: %s\n", current->url);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else if (current->next == NULL) {
        tail = newnode;
    }
}

void go_back() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

void go_forward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

void display_current_page() {
    if (current == NULL) {
        printf("No page visted yet.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[50];
    head = tail = current = NULL; 
    while (1) {
        printf("\n1. Visit a new page\n2. Go back\n3. Go forward\n4. Display current page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the URL to visit: ");
                scanf("%s", url);  
                visit(url); 
                break;
            case 2:
                go_back();
                break;
            case 3:
                go_forward();
                break;
            case 4:
                display_current_page();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
