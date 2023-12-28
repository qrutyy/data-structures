#include <stddef.h>
#include "unity.h"
#include "queue.h"

void test_add_to_queue(){
    struct Queue* Testqueue = createQueue(2);
    addToQueue(Testqueue, 52);
    addToQueue(Testqueue, 54);
    int32_t output_head = returnHead(Testqueue);
    int32_t output_tail = returnTail(Testqueue);
    TEST_ASSERT_EQUAL(52, output_head);
    TEST_ASSERT_EQUAL(54, output_tail);
}

void test_queue_is_full() {
    struct Queue* Testqueue = createQueue(5);
    addToQueue(Testqueue, 54);
    addToQueue(Testqueue, 55);
    addToQueue(Testqueue, 56);
    addToQueue(Testqueue, 57);
    addToQueue(Testqueue, 58);
    TEST_ASSERT_TRUE(isFull(Testqueue));
    TEST_ASSERT_FALSE(isEmpty(Testqueue));
}