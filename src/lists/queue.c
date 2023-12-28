#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int32_t head, size, tail;
    uint32_t capacity;
    int32_t* array;
};

struct Queue* createQueue(uint32_t current_capacity) {
    struct Queue* newQueue = malloc(sizeof(struct Queue));
    newQueue->capacity = current_capacity;
    newQueue->head = newQueue->size = 0;
    newQueue->tail = current_capacity - 1;
    newQueue->size = 0;
    newQueue->array = calloc(current_capacity, sizeof(int32_t));
    return newQueue;
}

bool isFull(struct Queue* currentQueue) {
    return currentQueue->size == currentQueue->capacity;
}

bool isEmpty(struct Queue* currentQueue) {
    return currentQueue->size == 0;
}

void addToQueue(struct Queue* currentQueue, int32_t value) {
    if (isFull(currentQueue)) {
        currentQueue->capacity *= 2;
        currentQueue->array = realloc(currentQueue->array, currentQueue->capacity);
    }
    currentQueue->tail = (currentQueue->tail + 1) % currentQueue->capacity;
    currentQueue->array[currentQueue->tail] = value;
    currentQueue->size++;
}

int removeFromQueue(struct Queue* currentQueue) {
    if (isEmpty(currentQueue)) {
        fprintf(stderr, "Current queue is empty\n");
        return INT32_MIN;
    }
    int32_t value = currentQueue->array[currentQueue->head];
    currentQueue->head = (currentQueue->head + 1) % currentQueue->capacity;
    currentQueue->size--;
    return value;
}

void printHead(struct Queue* currentQueue) {
    if (isEmpty(currentQueue)) {
        fprintf(stderr, "Current queue is empty\n");
        return;
    }
    printf("Head of queue is: %d\n", currentQueue->array[currentQueue->head]);
}

void printTail(struct Queue* currentQueue) {
    if (isEmpty(currentQueue)) {
        fprintf(stderr, "Current queue is empty\n");
        return;
    }
    printf("Tail of queue is: %d\n", currentQueue->array[currentQueue->tail]);
}

int32_t returnHead(struct Queue* currentQueue) {
    if (isEmpty(currentQueue)) {
        fprintf(stderr, "Current queue is empty\n");
        return -1;
    }
    return currentQueue->array[currentQueue->head];
}

int32_t returnTail(struct Queue* currentQueue) {
    if (isEmpty(currentQueue)) {
        fprintf(stderr, "Current queue is empty\n");
        return -1;
    }
    return currentQueue->array[currentQueue->tail];
}

