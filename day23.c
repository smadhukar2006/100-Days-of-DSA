#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    return result;
}


void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    scanf("%d", &m);

    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    
    struct Node* merged = mergeLists(list1, list2);

  
    traverse(merged);

    return 0;
}
