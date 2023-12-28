#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int32_t head, size, tail;
    uint32_t capacity;
    int32_t* array;
};

struct Queue* create_queue(uint32_t current_capacity) {
    struct Queue* new_queue = malloc(sizeof(struct Queue));
    new_queue->capacity = current_capacity;
    new_queue->head = new_queue->size = 0;
    new_queue->tail = current_capacity - 1;
    new_queue->size = 0;
    new_queue->array = calloc(current_capacity, sizeof(int32_t));
    return new_queue;
}

bool is_full(struct Queue* current_queue) {
    return current_queue->size == current_queue->capacity;
}

bool is_empty(struct Queue* current_queue) {
    return current_queue->size == 0;
}

void add_to_queue(struct Queue* current_queue, int32_t value) {
    if (is_full(current_queue)) {
        current_queue->capacity *= 2;
        current_queue->array = realloc(current_queue->array, current_queue->capacity);
    }
    current_queue->tail = (current_queue->tail + 1) % current_queue->capacity;
    current_queue->array[current_queue->tail] = value;
    current_queue->size++;
}

int remove_from_queue(struct Queue* current_queue) {
    if (is_empty(current_queue)) {
        fprintf(stderr, "Current queue is empty\n");
        return INT32_MIN;
    }
    int32_t value = current_queue->array[current_queue->head];
    current_queue->head = (current_queue->head + 1) % current_queue->capacity;
    current_queue->size--;
    return value;
}

void print_head(struct Queue* current_queue) {
    if (is_empty(current_queue)) {
        fprintf(stderr, "Current queue is empty\n");
        return;
    }
    printf("Head of queue is: %d\n", current_queue->array[current_queue->head]);
}

void print_tail(struct Queue* current_queue) {
    if (is_empty(current_queue)) {
        fprintf(stderr, "Current queue is empty\n");
        return;
    }
    printf("Tail of queue is: %d\n", current_queue->array[current_queue->tail]);
}

int32_t return_head(struct Queue* current_queue) {
    if (is_empty(current_queue)) {
        fprintf(stderr, "Current queue is empty\n");
        return -1;
    }
    return current_queue->array[current_queue->head];
}

int32_t return_tail(struct Queue* current_queue) {
    if (is_empty(current_queue)) {
        fprintf(stderr, "Current queue is empty\n");
        return -1;
    }
    return current_queue->array[current_queue->tail];
}

