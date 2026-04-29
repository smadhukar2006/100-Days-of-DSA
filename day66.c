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

int DFS(struct Graph* graph, int v, int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u] && DFS(graph, u, visited, recStack)) return 1;
        else if (recStack[u]) return 1;
        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* recStack = (int*)calloc(graph->V, sizeof(int));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (DFS(graph, i, visited, recStack)) return 1;
        }
    }
    return 0;
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

    if (hasCycle(graph)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
