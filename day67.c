#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

void DFS(struct Graph* graph, int v, int visited[], int* stack, int* top) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u]) DFS(graph, u, visited, stack, top);
        temp = temp->next;
    }
    stack[(*top)++] = v;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) DFS(graph, i, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);
    return 0;
}
