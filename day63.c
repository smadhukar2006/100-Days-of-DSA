#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v, int directed) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    if (!directed) {
        struct Node* node2 = createNode(u);
        node2->next = adj[v];
        adj[v] = node2;
    }
}

void DFS(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) DFS(adj, visited, temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n, m, directed, s;
    scanf("%d %d %d", &n, &m, &directed);
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }
    scanf("%d", &s);
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(adj, visited, s);
    printf("\n");
    return 0;
}
