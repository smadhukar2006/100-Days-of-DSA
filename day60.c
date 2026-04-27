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

int isMinHeap(struct Node* root) {
    if (root == NULL) return 1;
    if (root->left) {
        if (root->data > root->left->data) return 0;
    }
    if (root->right) {
        if (root->data > root->right->data) return 0;
    }
    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    if (isMinHeap(root)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
