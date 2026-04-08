#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    
    if (head == NULL) return head;

   
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);          
        return head;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

  
    if (temp == NULL) return head;

    
    prev->next = temp->next;
    free(temp);

    return head;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

  
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

  
    scanf("%d", &key);

    
    head = deleteFirstOccurrence(head, key);

    
    printList(head);

    return 0;
}
