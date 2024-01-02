#include <stddef.h>
#include "unity.h"
#include "sharedheader.h"

void test_queue_push(){
    struct Queue* test_queue = create_queue(2);
    push_queue(test_queue, 52);
    push_queue(test_queue, 54);
    TEST_ASSERT_EQUAL(52, peek_queue_head(test_queue));
    TEST_ASSERT_EQUAL(54, peek_queue_tail(test_queue));
    free_queue(test_queue);
}

void test_queue_is_full() {
    struct Queue* test_queue = create_queue(5);
    push_queue(test_queue, 54);
    push_queue(test_queue, 55);
    push_queue(test_queue, 56);
    push_queue(test_queue, 57);
    push_queue(test_queue, 58);
    TEST_ASSERT_TRUE(is_queue_full(test_queue));
    TEST_ASSERT_FALSE(is_queue_empty(test_queue));
    free_queue(test_queue);
}

void test_queue_isnt_full() {
    struct Queue* test_queue = create_queue(5);
    push_queue(test_queue, 54);
    push_queue(test_queue, 55);
    push_queue(test_queue, 56);
    push_queue(test_queue, 57);
    TEST_ASSERT_FALSE(is_queue_full(test_queue));
    TEST_ASSERT_FALSE(is_queue_empty(test_queue));
    free_queue(test_queue);
}

void test_queue_is_empty() {
    struct Queue* test_queue = create_queue(5);
    TEST_ASSERT_TRUE(is_queue_empty(test_queue));
    TEST_ASSERT_FALSE(is_queue_full(test_queue));
    free_queue(test_queue);
}

void test_queue_overflow() {
    struct Queue* test_queue = create_queue(5);
    push_queue(test_queue, 3123912);
    push_queue(test_queue, 31923);
    push_queue(test_queue, 5849381);
    push_queue(test_queue, 954);
    push_queue(test_queue, 2);
    push_queue(test_queue, 89324);
    push_queue(test_queue, 8412);
    push_queue(test_queue, 27);
    TEST_ASSERT_EQUAL(3123912, peek_queue_head(test_queue));
    TEST_ASSERT_EQUAL(27, peek_queue_tail(test_queue));
    TEST_ASSERT_FALSE(is_queue_full(test_queue));
    free_queue(test_queue);
}

void test_queue_removing_from_empty() {
    struct Queue* test_queue = create_queue(5);
    TEST_ASSERT_EQUAL(INT32_MIN, pop_queue(test_queue));
    free_queue(test_queue);
}

void test_queue_removing_from_not_empty() {
    struct Queue* test_queue = create_queue(5);
    push_queue(test_queue, 31233912);
    push_queue(test_queue, 31923);
    push_queue(test_queue, 5849381);
    push_queue(test_queue, 954);
    push_queue(test_queue, 2);
    push_queue(test_queue, 89324);
    push_queue(test_queue, 8412);
    push_queue(test_queue, 27);
    TEST_ASSERT_EQUAL(3123912, pop_queue(test_queue));
    free_queue(test_queue);
}

void test_queue_check_ht_after_removing() {
    struct Queue* test_queue = create_queue(5);
    push_queue(test_queue, 3123912);
    push_queue(test_queue, 31923);
    push_queue(test_queue, 5849381);
    push_queue(test_queue, 954);
    push_queue(test_queue, 2);
    push_queue(test_queue, 89324);
    pop_queue(test_queue);
    pop_queue(test_queue);
    pop_queue(test_queue);
    pop_queue(test_queue);
    pop_queue(test_queue);
    pop_queue(test_queue);
    TEST_ASSERT_TRUE(is_queue_empty(test_queue));
    TEST_ASSERT_FALSE(is_queue_full(test_queue));
    TEST_ASSERT_EQUAL(-1, peek_queue_head(test_queue));
    TEST_ASSERT_EQUAL(-1, peek_queue_tail(test_queue));
    free_queue(test_queue);
}

void setUp()
{

}

void tearDown()
{

}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_queue_push);
    RUN_TEST(test_queue_is_full);
    RUN_TEST(test_queue_isnt_full);
    RUN_TEST(test_queue_is_empty);
    RUN_TEST(test_queue_overflow);
    RUN_TEST(test_queue_removing_from_empty);
    RUN_TEST(test_queue_removing_from_not_empty);
    RUN_TEST(test_queue_check_ht_after_removing);
    UNITY_END();

    return 0;
}
