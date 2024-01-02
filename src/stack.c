#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct Stack {
    int32_t head;
    uint32_t capacity;
    int32_t *array;
};

struct Stack* create_stack(uint32_t curr_capacity) {
    struct Stack* new_stack = malloc(sizeof(struct Stack));
    if (new_stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_stack->capacity = curr_capacity;
    new_stack->head = -1;
    new_stack->array = calloc(curr_capacity, sizeof(int32_t));
    if (new_stack->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return new_stack;
}

bool is_stack_full(struct Stack* current_stack) {
    return current_stack->capacity - 1 == current_stack->head;
}

bool is_stack_empty(struct Stack* current_stack) {
    return current_stack->head == -1;
}

void push_stack(struct Stack* current_stack, int32_t value) {
    if (is_stack_full(current_stack)) {
        current_stack->capacity *= 2;
        current_stack->array = realloc(current_stack->array, current_stack->capacity);
        if (current_stack->array == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    current_stack->array[++current_stack->head] = value;
}

int32_t pop_stack(struct Stack* current_stack) {
    if(is_stack_empty(current_stack)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return INT32_MIN;
    }
    return current_stack->array[current_stack->head--];
}

int32_t peek_stack(struct Stack* current_stack) {
    if(is_stack_empty(current_stack)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return INT32_MIN;
    }
    return current_stack->array[current_stack->head];
}

void free_stack(struct Stack* current_stack) {
    free(current_stack);
}