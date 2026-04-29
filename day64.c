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

struct Queue {
    int* arr;
    int front, rear, size;
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
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear < q->front;
}

void enqueue(struct Queue* q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

void BFS(struct Graph* graph, int s) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    struct Queue* q = createQueue(graph->V);

    visited[s] = 1;
    enqueue(q, s);

    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d ", u);

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(q, v);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            addEdge(graph, i, v);
        }
    }

    scanf("%d", &s);
    BFS(graph, s);

    return 0;
}
