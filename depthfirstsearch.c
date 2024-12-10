#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
struct Node {
 int dest;
 struct Node* next;
};
struct AdjList {
 struct Node* head;
};
struct Node* createNode(int dest) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
 newNode->dest = dest;
 newNode->next = NULL;
 return newNode;
}
void addEdge(struct AdjList adj[], int u, int v) {
 struct Node* newNode = createNode(v);
 newNode->next = adj[u].head;
 adj[u].head = newNode;
 newNode = createNode(u);
 newNode->next = adj[v].head;
 adj[v].head = newNode;
}
void DFSRec(struct AdjList adj[], int visited[], int s) {
 visited[s] = 1;
 printf("%d ", s);
 struct Node* current = adj[s].head;
 while (current != NULL) {
 int dest = current->dest;
 if (!visited[dest]) {
 DFSRec(adj, visited, dest);
 }
 current = current->next;
 }
}
void DFS(struct AdjList adj[], int V, int s) {
 int visited[V];
 for (int i = 0; i < V; i++) {
 visited[i] = 0;
 }
 printf("DFS traversal starting from vertex %d:\n", s);
 DFSRec(adj, visited, s);
 printf("\n");
}
void BFS(struct AdjList adj[], int V, int s) {
 bool visited[MAX] = { false }; // Mark all vertices as not visited
 int queue[MAX], front = 0, rear = 0;
 visited[s] = true;
 queue[rear++] = s;
 printf("BFS traversal starting from vertex %d:\n", s);
 while (front < rear) {
 int curr = queue[front++];
 printf("%d ", curr);
 struct Node* current = adj[curr].head;
 while (current != NULL) {
 int dest = current->dest;
 if (!visited[dest]) {
 visited[dest] = true;
 queue[rear++] = dest;
 }
 current = current->next;
 }
 }
 printf("\n");
}
int main() {
 int V, E, u, v, sourceDFS, sourceBFS;
 printf("Enter the number of vertices: ");
 scanf("%d", &V);
 printf("Enter the number of edges: ");
 scanf("%d", &E);
 struct AdjList adj[V];
 for (int i = 0; i < V; i++) {
 adj[i].head = NULL;
 }
 printf("Enter the edges (u v):\n");
 for (int i = 0; i < E; i++) {
     scanf("%d %d", &u, &v);
 addEdge(adj, u, v);
 }
 printf("Enter the starting vertex for DFS: ");
 scanf("%d", &sourceDFS);
 DFS(adj, V, sourceDFS);
 printf("Enter the starting vertex for BFS: ");
 scanf("%d", &sourceBFS);
 BFS(adj, V, sourceBFS);
 return 0;
}
