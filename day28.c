#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* createCircularList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = newNode(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    if (tail != NULL) tail->next = head;
    return head;
}

void traverseCircularList(struct Node* head, int n) {
    if (head == NULL) return;
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = createCircularList(n);
    traverseCircularList(head, n);
    return 0;
}
