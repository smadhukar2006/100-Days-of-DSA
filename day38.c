#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int count = 0;

void push_front(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;
    if (front == NULL) {
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }
    count++;
}

void push_back(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    count++;
}

void pop_front() {
    if (front == NULL) return;
    struct Node* temp = front;
    front = front->next;
    if (front != NULL) front->prev = NULL;
    else rear = NULL;
    free(temp);
    count--;
}

void pop_back() {
    if (rear == NULL) return;
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear != NULL) rear->next = NULL;
    else front = NULL;
    free(temp);
    count--;
}

int get_front() {
    if (front == NULL) return -1;
    return front->data;
}

int get_back() {
    if (rear == NULL) return -1;
    return rear->data;
}

int empty() {
    return front == NULL;
}

int size() {
    return count;
}

void clear() {
    while (front != NULL) pop_front();
}

void reverse() {
    struct Node* curr = front;
    struct Node* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL) {
        rear = front;
        front = temp->prev;
    }
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "display") == 0) {
            display();
        }
    }
    return 0;
}
