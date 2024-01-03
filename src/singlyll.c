#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int32_t data;
    struct Node *next;
};

struct Node* create_slist_node(int32_t value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

bool is_slist_empty(struct Node* head) {
    return head == NULL;
}

void push_slist_end(struct Node** head, int32_t value) {
    struct Node* new_node = create_slist_node(value);
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

void push_slist_beginning(struct Node** head, int32_t value) {
    struct Node* new_node = create_slist_node(value);
    new_node->next = *head;
    *head = new_node;
}

int32_t peek_slist_head(struct Node* head) {
    if (is_slist_empty(head)) {
        fprintf(stderr, "Current linked list is empty\n");
        return INT32_MIN;
    }
    return head->data;
}

int32_t peek_slist_tail(struct Node* head) {
    if (is_slist_empty(head)) {
        fprintf(stderr, "Current linked list is empty\n");
        return INT32_MIN;
    }
    while (head->next != NULL) {
        printf("-> %d ", head->data);
        head = head->next;
    }
    return head->data;
}

int32_t pop_slist(struct Node** head) {
    if (*head == NULL) {
        fprintf(stderr, "Current linked list is empty\n Cannot pop");
        return INT32_MIN;
    }
    struct Node* popped_node = *head;
    *head = popped_node->next;

    int popped_data = popped_node->data;
    free(popped_node); 
    return popped_data;
}

//function that searches for a value in an entire l-l and the removes it once.

void remove_value_slist(struct Node** head, int32_t value) {
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

void print_slist(struct Node* head) {
    printf("Printing singly linked list:\nStart ");
    while (head != NULL) {
        printf("-> %d ", head->data);
        head = head->next;
    }
    printf("-> End\n");
}

void free_slist(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}