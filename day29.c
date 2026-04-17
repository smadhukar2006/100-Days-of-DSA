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

void insertEnd(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;
    int len = getLength(head);
    k = k % len;
    if (k == 0) return head;

    struct Node* temp = head;
    for (int i = 1; i < len; i++) temp = temp->next;
    temp->next = head;

    int steps = len - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}
