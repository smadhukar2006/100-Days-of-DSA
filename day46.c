#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

struct Queue {
    struct Node* data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

void enqueue(struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = node;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

struct Node* dequeue() {
    if (front == NULL) return NULL;
    struct Node* val = front->data;
    struct Queue* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int isEmpty() {
    return front == NULL;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left != NULL) enqueue(curr->left);
        if (curr->right != NULL) enqueue(curr->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    levelOrder(root);
    return 0;
}
