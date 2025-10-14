#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 15

int queue[MAX_VERTICES], front = -1, rear = -1;
int visited[MAX_VERTICES];

void enqueue(int value) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = queue[front];
    front = front + 1;
    return value;
}

void bfs(int adj[MAX_VERTICES][MAX_VERTICES], int start, int n) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current + 1);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int adj[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &start);

    start = start - 1;

    bfs(adj, start, n);

    return 0;
}
