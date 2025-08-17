#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

int deque[MAX];
int dq_front = -1, dq_rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n"); 
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
    printf("%d enqueued\n", val);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front++];
    printf("%d dequeued\n", val);
    return val;
}

void display_queue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void dq_insert_front(int val) {
    if (dq_front == 0 && dq_rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq_front == -1) {
        dq_front = dq_rear = 0;
    } else if (dq_front > 0) {
        dq_front--;
    } else {
        for (int i = dq_rear; i >= dq_front; i--)
            deque[i + 1] = deque[i];
        dq_rear++;
    }
    deque[dq_front] = val;
    printf("%d inserted at front\n", val);
}

void dq_insert_rear(int val) {
    if (dq_rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq_front == -1) {
        dq_front = dq_rear = 0;
    } else {
        dq_rear++;
    }
    deque[dq_rear] = val;
    printf("%d inserted at rear\n", val);
}

int dq_delete_front() {
    if (dq_front == -1 || dq_front > dq_rear) {
        printf("Deque Underflow\n");
        return -1;
    }
    int val = deque[dq_front++];
    printf("%d deleted from front\n", val);
    return val;
}

int dq_delete_rear() {
    if (dq_front == -1 || dq_front > dq_rear) {
        printf("Deque Underflow\n");
        return -1;
    }
    int val = deque[dq_rear--];
    printf("%d deleted from rear\n", val);
    return val;
}

void display_deque() {
    if (dq_front == -1 || dq_front > dq_rear) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = dq_front; i <= dq_rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

void queue_menu() {
    int choice, val;
    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

void deque_menu() {
    int choice, val;
    while (1) {
        printf("\n--- Deque Operations ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Back to Main Menu\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                dq_insert_front(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                dq_insert_rear(val);
                break;
            case 3:
                dq_delete_front();
                break;
            case 4:
                dq_delete_rear();
                break;
            case 5:
                display_deque();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Queue\n2. Deque\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                queue_menu();
                break;
            case 2:
                deque_menu();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
