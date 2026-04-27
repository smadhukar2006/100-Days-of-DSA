#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = createNode(arr[i]);
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;
    while (front < rear) {
        int size = rear - front;
        int level[size];
        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];
            level[i] = node->data;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        if (leftToRight) {
            for (int i = 0; i < size; i++) printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--) printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}
