#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


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

int isFull(struct Queue* currentQueue) {
    return currentQueue->size == currentQueue->capacity;
}

int isEmpty(struct Queue* currentQueue) {
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

int main() {
    struct Queue* currentQueue = createQueue(5);

    addToQueue(currentQueue, 10);
    addToQueue(currentQueue, 12);
    addToQueue(currentQueue, 13);
    addToQueue(currentQueue, 14);
    addToQueue(currentQueue, 16);
    printf("result of isfull %d\n",isFull(currentQueue));
    printf("result of isempty %d\n",isEmpty(currentQueue));
    printHead(currentQueue);
    printTail(currentQueue);
    removeFromQueue(currentQueue);
    printHead(currentQueue);
    printTail(currentQueue);

}