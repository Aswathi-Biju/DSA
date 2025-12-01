/*Implement backward and forward navigation of visited web pages in a web browser 
(i.e. back and forward buttons) using doubly linked list operations.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char page[50];
    struct Node* prev;
    struct Node* next;
};

struct Node* visited(struct Node** current, struct Node* newPage){
    newPage->prev = *current;
    if(*current != NULL){
        (*current)->next=newPage;
    }
    *current=newPage;
    return *current;
}

void forward(struct Node** current){
    if(*current && (*current)->next){
        *current=(*current)->next;
        printf("Moved FORWARD-> %s\n", (*current)->page);
    }else{
        printf("Cannot move forward any more\n");
    }
}

void backward(struct Node** current){
    if(*current && (*current)->prev){
        *current=(*current)->prev;
        printf("Moved BACKWARD-> %s\n", (*current)->page);
    }else{
        printf("Cannot move backward any more\n");
    }
}

int main(){
    struct Node* p1 =  malloc(sizeof(struct Node));
    struct Node* p2 =  malloc(sizeof(struct Node));
    struct Node* p3 =  malloc(sizeof(struct Node));

    strcpy(p1->page,"google.com");
    strcpy(p2->page,"youtube.com");
    strcpy(p3->page,"instagram.com");

    p1->prev = p1->next = NULL;
    p2->prev = p2->next = NULL;
    p3->prev = p3->next = NULL;

    struct Node* current= NULL;

    visited(&current,p1);
    printf("Visited page: %s\n",current->page);
    visited(&current,p2);
    printf("Visited page: %s\n",current->page);
    visited(&current,p3);
    printf("Visited page: %s\n",current->page);

    forward(&current);
    backward(&current);
    backward(&current);
    forward(&current);

    return 0;
}