#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block {
    int start;
    int size;
    int is_free;
    struct Block *next, *prev;
};

struct Block *head = NULL;

struct Block* create_block(int start, int size, int is_free) {
    struct Block *new_block = (struct Block*)malloc(sizeof(struct Block));
    new_block->start = start;
    new_block->size = size;
    new_block->is_free = is_free;
    new_block->next = NULL;
    new_block->prev = NULL;
    return new_block;
}

void add_block(int start, int size, int is_free) {
    struct Block *new_block = create_block(start, size, is_free);
    if (head == NULL) {
        head = new_block;
        return;
    }
    struct Block *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_block;
    new_block->prev = temp;
}

void display_memory() {
    struct Block *temp = head;
    printf("\nStart\tSize\tStatus\n");
    while (temp != NULL) {
        printf("%d\t%d\t%s\n", temp->start, temp->size, temp->is_free ? "Free" : "Used");
        temp = temp->next;
    }
}

void garbage_collection() {
    struct Block *temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->is_free && temp->next->is_free) {
            temp->size += temp->next->size;
            struct Block *to_delete = temp->next;
            temp->next = to_delete->next;
            if (to_delete->next != NULL)
                to_delete->next->prev = temp;
            free(to_delete);
        } else {
            temp = temp->next;
        }
    }
}

void first_fit(int process_size) {
    struct Block *temp = head;
    while (temp != NULL) {
        if (temp->is_free && temp->size >= process_size) {
            temp->is_free = 0;
            if (temp->size > process_size) {
                int new_start = temp->start + process_size;
                int new_size = temp->size - process_size;
                temp->size = process_size;
                struct Block *new_block = create_block(new_start, new_size, 1);
                new_block->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = new_block;
                temp->next = new_block;
                new_block->prev = temp;
            }
            return;
        }
        temp = temp->next;
    }
}

void best_fit(int process_size) {
    struct Block *temp = head, *best = NULL;
    while (temp != NULL) {
        if (temp->is_free && temp->size >= process_size) {
            if (best == NULL || temp->size < best->size)
                best = temp;
        }
        temp = temp->next;
    }
    if (best != NULL) {
        best->is_free = 0;
        if (best->size > process_size) {
            int new_start = best->start + process_size;
            int new_size = best->size - process_size;
            best->size = process_size;
            struct Block *new_block = create_block(new_start, new_size, 1);
            new_block->next = best->next;
            if (best->next != NULL)
                best->next->prev = new_block;
            best->next = new_block;
            new_block->prev = best;
        }
    }
}

void worst_fit(int process_size) {
    struct Block *temp = head, *worst = NULL;
    while (temp != NULL) {
        if (temp->is_free && temp->size >= process_size) {
            if (worst == NULL || temp->size > worst->size)
                worst = temp;
        }
        temp = temp->next;
    }
    if (worst != NULL) {
        worst->is_free = 0;
        if (worst->size > process_size) {
            int new_start = worst->start + process_size;
            int new_size = worst->size - process_size;
            worst->size = process_size;
            struct Block *new_block = create_block(new_start, new_size, 1);
            new_block->next = worst->next;
            if (worst->next != NULL)
                worst->next->prev = new_block;
            worst->next = new_block;
            new_block->prev = worst;
        }
    }
}

int main() {
    add_block(1000, 200, 0);
    add_block(1200, 150, 1);
    add_block(1350, 300, 0);
    add_block(1650, 100, 1);
    add_block(1750, 200, 1);

    printf("Initial Memory:\n");
    display_memory();

    printf("\nFirst Fit (Process 120):\n");
    first_fit(120);
    display_memory();

    printf("\nBest Fit (Process 80):\n");
    best_fit(80);
    display_memory();

    printf("\nWorst Fit (Process 100):\n");
    worst_fit(100);
    display_memory();

    printf("\nAfter Garbage Collection:\n");
    garbage_collection();
    display_memory();

    return 0;
}
