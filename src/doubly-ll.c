#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct Node {
    uint32_t data;
    struct Node *next;
    struct Node *prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void addEndNode(uint32_t value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    tail = newNode;

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
    if (tail == NULL) {
        tail = newNode;
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

void deleteEnding() {
    struct Node* newTail = tail->prev;
    newTail->next = NULL;
    free(tail);
    tail = newTail;
}

void deleteStarting() {
    struct Node* newHead = head->next;
    newHead->prev = NULL;
    free(head);
    head = newHead;
}

int main() {
    printf("Initial test...\n");
    addStartNode(15);
    addEndNode(16);
    addEndNode(17);
    addStartNode(14);
    deleteEnding();
    deleteStarting();
    printLinkedList();
    return 0;
}

