#include <stdint.h>
#include <stdbool.h>

#ifndef QUEUE_SECTION_H
#define QUEUE_SECTION_H

struct Queue* create_queue(uint32_t current_capacity);
bool is_queue_full(struct Queue* currentQueue);
bool is_queue_empty(struct Queue* currentQueue);
void push_queue(struct Queue* currentQueue, int32_t value);
int32_t pop_queue(struct Queue* currentQueue);
int32_t peek_queue_tail(struct Queue* currentQueue);
int32_t peek_queue_head(struct Queue* currentQueue);
void free_queue(struct Queue* current_queue);

#endif

#ifndef STACK_SECTION_H
#define STACK_SECTION_H

struct Stack* create_stack(uint32_t curr_capacity);
bool is_stack_full(struct Stack* current_stack);
bool is_stack_empty(struct Stack* current_stack);
void push_stack(struct Stack* current_stack, int32_t value);
int32_t pop_stack(struct Stack* current_stack);
int32_t peek_stack(struct Stack* current_stack);
void free_stack(struct Stack* current_stack);

#endif

#ifndef SINGLYLL_SECTION_H
#define SINGLYLL_SECTION_H

struct Node* create_slist_node(int32_t value);
bool is_slist_empty(struct Node* head);
void push_slist_end(struct Node** head, int32_t value);
void push_slist_beginning(struct Node** head, int32_t value);
void remove_value_slist(struct Node** head, int32_t value);
int32_t pop_slist(struct Node** head);
int32_t peek_slist_head(struct Node* head);
int32_t peek_slist_tail(struct Node* head);
void print_slist(struct Node* head);
void free_slist(struct Node** head);

#endif

#ifndef DOUBLYLL_SECTION_H
#define DOUBLYLL_SECTION_H

struct Node* create_dlist_node(int32_t value);
bool is_dlist_empty(struct Node* head);
void push_dlist_end(struct Node** head, int32_t value);
void push_dlist_beginning(struct Node** head, int32_t value);
void remove_value_dlist(struct Node** head, int32_t value);
int32_t peek_dlist_head(struct Node* head);
int32_t peek_dlist_tail(struct Node* head);
int32_t pop_dlist(struct Node** head);
void print_dlist_forward(struct Node* head);
void print_dlist_backward(struct Node* head);
void free_dlist(struct Node** head);

#endif
