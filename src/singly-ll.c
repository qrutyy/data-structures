#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct Node {
    int32_t data;
    struct Node *next;
};

struct Node* create_node(int32_t value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

void insert_at_end(struct Node** head, int32_t value) {
    struct Node* new_node = create_node(value);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_beginning(struct Node** head, int32_t value) {
    struct Node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void printLinkedList(struct Node* head) {
    printf("Printing singly linked list:\nStart ");
    while (head != NULL) {
        printf("-> %d ", head->data);
        head = head->next;
    }
    printf("-> End\n");
}

void deleteNode(struct Node** head, int32_t value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
