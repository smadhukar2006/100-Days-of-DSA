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

struct Queue {
    int* arr;
    int front, rear;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
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

void topologicalSort(struct Graph* graph) {
    int* indegree = (int*)calloc(graph->V, sizeof(int));

    for (int u = 0; u < graph->V; u++) {
        struct Node* temp = graph->adj[u];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    struct Queue* q = createQueue(graph->V);
    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0) enqueue(q, i);
    }

    int count = 0;
    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d ", u);
        count++;

        struct Node* temp = graph->adj[u];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) enqueue(q, temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n");

    if (count != graph->V) {
        printf("Graph is not a DAG\n");
    }
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
