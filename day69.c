#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
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

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

struct HeapNode {
    int vertex, dist;
};

struct MinHeap {
    int size, capacity;
    int* pos;
    struct HeapNode** array;
};

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = heap->array[smallest];
        struct HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;

    struct HeapNode* root = heap->array[0];
    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct MinHeap* heap = createMinHeap(V);
    for (int v = 0; v < V; v++) {
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }
    heap->size = V;

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            if (heap->pos[v] < heap->size && dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    scanf("%d", &src);
    dijkstra(graph, src);

    return 0;
}
