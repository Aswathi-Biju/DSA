//Implement BFS using arrays.

#include<stdio.h>
int queue[100];
int f=-1,r=-1;
int visited[6];

int enqueue(int x){
    if(f==-1) f=0;
    queue[++r]=x;
}

int dequeue(){
    if(f==-1 ||f>r) return -1;
    return queue[f++];
}

void bfs(int graph[6][6],int s){
    for(int i =0; i<6; i++) visited[i]=0;
    enqueue(s);
    visited[s]=1;
    printf("BFS Traversal: ");
    while(f<=r){
        int node = dequeue();
        printf("%d ", node);
        for(int i=0; i<6; i++){
            if(graph[node][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }
    }

}

int main(){
    int graph[6][6] = {
        {0,1,1,0,0,0},
        {1,0,0,1,0,0},
        {1,0,0,1,1,0},
        {0,1,1,0,1,1},
        {0,0,1,1,0,1},
        {0,0,0,1,1,0}
    };
    bfs(graph,0);
    return 0;
}