#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int32_t data;
    struct Node *next;
    struct Node *prev;
};

struct Node* create_dlist_node(int32_t value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = value;
    return new_node;
}

bool is_dlist_empty(struct Node* head) {
    return head == NULL;
}

void push_dlist_end(struct Node** head, int32_t value) {
    struct Node* new_node = create_dlist_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void push_dlist_beginning(struct Node** head, int32_t value) {
    struct Node* new_node = create_dlist_node(value);
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

int32_t peek_dlist_head(struct Node* head) {
    if (is_dlist_empty(head)) {
        fprintf(stderr, "Current linked list is empty\n");
        return INT32_MIN;
    }
    return head->data;
}

int32_t peek_dlist_tail(struct Node* head) {
    if (is_dlist_empty(head)) {
        fprintf(stderr, "Current linked list is empty\n");
        return INT32_MIN;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    return head->data;
}

int32_t pop_dlist(struct Node** head) {
    if (*head == NULL) {
        fprintf(stderr, "Current linked list is empty\n Cannot pop");
        return INT32_MIN;
    }
    struct Node* popped_node = *head;
    *head = popped_node->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    int popped_data = popped_node->data;
    free(popped_node); 
    return popped_data;
}

// Function that searches for a value in an entire doubly linked list and then removes it

void remove_value_dlist(struct Node** head, int32_t value) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } 
    else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void print_dlist_forward(struct Node* head) {
    printf("Doubly Linked List (Forward): ");
    while (head != NULL) {
        printf("-> %d ", head->data);
        head = head->next;
    }
    printf("-> End");
}

void print_dlist_backward(struct Node* head) {
    if (head == NULL) {
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    printf("Doubly Linked List (Backward): ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

void free_dlist(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

