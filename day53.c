#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (root == NULL) return;
    struct Pair queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Pair){root, 0};
    int minHD = INT_MAX, maxHD = INT_MIN;
    int map[2000][1000], count[2000];
    for (int i = 0; i < 2000; i++) count[i] = 0;
    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* node = p.node;
        int hd = p.hd;
        int idx = hd + 1000;
        map[idx][count[idx]++] = node->data;
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
        if (node->left) queue[rear++] = (struct Pair){node->left, hd - 1};
        if (node->right) queue[rear++] = (struct Pair){node->right, hd + 1};
    }
    for (int hd = minHD; hd <= maxHD; hd++) {
        int idx = hd + 1000;
        for (int i = 0; i < count[idx]; i++) {
            printf("%d ", map[idx][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}
