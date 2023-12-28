#include <stddef.h>
#include "unity.h"
#include "queue.h"

void test_add_to_queue(){
    struct Queue* test_queue = create_queue(2);
    add_to_queue(test_queue, 52);
    add_to_queue(test_queue, 54);
    int32_t output_head = return_head(test_queue);
    int32_t output_tail = return_tail(test_queue);
    TEST_ASSERT_EQUAL(52, output_head);
    TEST_ASSERT_EQUAL(54, output_tail);
}

void test_queue_is_full() {
    struct Queue* test_queue = create_queue(5);
    add_to_queue(test_queue, 54);
    add_to_queue(test_queue, 55);
    add_to_queue(test_queue, 56);
    add_to_queue(test_queue, 57);
    add_to_queue(test_queue, 58);
    TEST_ASSERT_TRUE(is_full(test_queue));
    TEST_ASSERT_FALSE(is_empty(test_queue));
}

void setUp()
{

}

void tearDown()
{

}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_to_queue);
    RUN_TEST(test_queue_is_full);

    UNITY_END();

    return 0;
}
