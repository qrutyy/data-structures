#include <stdint.h>
#include <stdbool.h>
#ifndef QUEUE_SECTION_H
#define QUEUE_SECTION_H

struct Queue* create_queue(uint32_t current_capacity);
bool is_queue_full(struct Queue* currentQueue);
bool is_queue_empty(struct Queue* currentQueue);
void push_queue(struct Queue* currentQueue, int32_t value);
int pop_queue(struct Queue* currentQueue);
int32_t peek_queue_tail(struct Queue* currentQueue);
int32_t peek_queue_head(struct Queue* currentQueue);

#endif

#ifndef STACK_SECTION_H
#define STACK_SECTION_H

struct Stack* create_stack(uint32_t curr_capacity);
bool is_stack_full(struct Stack* current_stack);
bool is_stack_empty(struct Stack* current_stack);
void push_stack(struct Stack* current_stack, int32_t value);
int32_t pop_stack(struct Stack* current_stack);
int32_t peek_stack(struct Stack* current_stack);

#endif


