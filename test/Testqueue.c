#include <stddef.h>
#include "unity.h"
#include "queue.h"

void test_add_to_queue(){
    struct Queue* test_queue = create_queue(2);
    add_to_queue(test_queue, 52);
    add_to_queue(test_queue, 54);
    TEST_ASSERT_EQUAL(52, return_head(test_queue));
    TEST_ASSERT_EQUAL(54, return_tail(test_queue));
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

void test_queue_isnt_full() {
    struct Queue* test_queue = create_queue(5);
    add_to_queue(test_queue, 54);
    add_to_queue(test_queue, 55);
    add_to_queue(test_queue, 56);
    add_to_queue(test_queue, 57);
    add_to_queue(test_queue, 58);
    TEST_ASSERT_TRUE(is_full(test_queue));
    TEST_ASSERT_FALSE(is_empty(test_queue));
}

void test_queue_overflow() {
    struct Queue* test_queue = create_queue(5);
    add_to_queue(test_queue, 3123912);
    add_to_queue(test_queue, 31923);
    add_to_queue(test_queue, 5849381);
    add_to_queue(test_queue, 954);
    add_to_queue(test_queue, 2);
    add_to_queue(test_queue, 89324);
    add_to_queue(test_queue, 8412);
    add_to_queue(test_queue, 27);
    TEST_ASSERT_EQUAL(3123912, return_head(test_queue));
    TEST_ASSERT_EQUAL(27, return_tail(test_queue));
}

void test_removing_from_empty() {
    struct Queue* test_queue = create_queue(5);
    TEST_ASSERT_EQUAL(INT32_MIN, remove_from_queue(test_queue));
}

void test_removing_from_not_empty() {
    struct Queue* test_queue = create_queue(5);
    add_to_queue(test_queue, 3123912);
    add_to_queue(test_queue, 31923);
    add_to_queue(test_queue, 5849381);
    add_to_queue(test_queue, 954);
    add_to_queue(test_queue, 2);
    add_to_queue(test_queue, 89324);
    add_to_queue(test_queue, 8412);
    add_to_queue(test_queue, 27);
    TEST_ASSERT_EQUAL(3123912, remove_from_queue(test_queue));
}

void test_check_ht_after_removing() {
    struct Queue* test_queue = create_queue(5);
    add_to_queue(test_queue, 3123912);
    add_to_queue(test_queue, 31923);
    add_to_queue(test_queue, 5849381);
    add_to_queue(test_queue, 954);
    add_to_queue(test_queue, 2);
    add_to_queue(test_queue, 89324);
    remove_from_queue(test_queue);
    remove_from_queue(test_queue);
    remove_from_queue(test_queue);
    remove_from_queue(test_queue);
    remove_from_queue(test_queue);
    remove_from_queue(test_queue);
    TEST_ASSERT_TRUE(is_empty(test_queue));
    TEST_ASSERT_FALSE(is_full(test_queue));
    TEST_ASSERT_EQUAL(-1, return_head(test_queue));
    TEST_ASSERT_EQUAL(-1, return_tail(test_queue));


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
    RUN_TEST(test_queue_isnt_full);
    RUN_TEST(test_queue_overflow);
    RUN_TEST(test_removing_from_empty);
    RUN_TEST(test_removing_from_not_empty);
    RUN_TEST(test_check_ht_after_removing);
    UNITY_END();

    return 0;
}
