#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct Node {
    uint32_t data;
    struct Node *next;
};

struct Node* head = NULL;

void addEndNode(uint32_t value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addStartNode(uint32_t value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head != NULL) {
        newNode->next = head;
    }
    head = newNode;
}

void printLinkedList() {
    struct Node* current = head;
    printf("Printing singly linked list:\nStart ");

    while (current != NULL) {
        printf("-> %d ", current->data);
        current = current->next;
    }
    printf("-> End\n");
}

void deleteStarting() {
    struct Node* newHead = head->next;
    free(head);
    head = newHead;
}

int main() {
    printf("Initial test...\n");
    addStartNode(15);
    addEndNode(16);
    addEndNode(17);
    addStartNode(14);
    printLinkedList();
    deleteStarting();
    return 0;
}

