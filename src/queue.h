#include <stdint.h>
#include <stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H

struct Queue* create_queue(uint32_t current_capacity);
bool is_full(struct Queue* currentQueue);
bool is_empty(struct Queue* currentQueue);
void add_to_queue(struct Queue* currentQueue, int32_t value);
int remove_from_queue(struct Queue* currentQueue);
void print_head(struct Queue* currentQueue);
void print_tail(struct Queue* currentQueue);
int32_t return_tail(struct Queue* currentQueue);
int32_t return_head(struct Queue* currentQueue);

#endif