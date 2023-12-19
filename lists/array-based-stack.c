#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct Stack {
    int32_t head;
    uint32_t capacity;
    int32_t *array;
};

struct Stack* createNewStack(uint32_t curr_capacity) {
    struct Stack* newStack = malloc(sizeof(struct Stack));
    newStack->capacity = curr_capacity;
    newStack->head = -1;
    newStack->array = calloc(curr_capacity, sizeof(int32_t));
    return newStack;
}

int isFull(struct Stack* currStack) {
    return currStack->capacity - 1 == currStack->head;
}

int isEmpty(struct Stack* currStack) {
    return currStack->head == -1;
}

void pushStack(struct Stack* currStack, int32_t value) {
    if (isFull(currStack)) {
        currStack->capacity *= 2;
        currStack->array = realloc(currStack->array, currStack->capacity);
    }
    currStack->array[++currStack->head] = value;
}

int32_t popStack(struct Stack* currStack) {
    if(isEmpty(currStack)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return INT32_MIN;
    }
    return currStack->array[currStack->head--];
}

int32_t peekStack(struct Stack* currStack) {
    if(isEmpty(currStack)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return INT32_MIN;
    }
    printf("%d\n", currStack->array[currStack->head]);
    return 0;
}

int main() {
    struct Stack* newStack = createNewStack(5);
    pushStack(newStack, 6);
    pushStack(newStack, 7);
    pushStack(newStack, 8);
    pushStack(newStack, 10);
    peekStack(newStack);
    popStack(newStack);
    peekStack(newStack);


    return 0;
}