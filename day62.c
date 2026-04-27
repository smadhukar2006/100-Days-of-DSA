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

void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m, directed;
    scanf("%d %d %d", &n, &m, &directed);
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }
    printGraph(adj, n);
    return 0;
}

