#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* newNode(int coeff, int exp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* node = newNode(coeff, exp);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* poly = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly, coeff, exp);
    }
    displayPolynomial(poly);
    return 0;
}
