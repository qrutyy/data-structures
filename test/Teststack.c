#include <stddef.h>
#include "unity.h"
#include "sharedheader.h"

void test_stack_push() {
    struct Stack* test_stack = create_stack(5);
    push_stack(test_stack, 2);
    push_stack(test_stack, 56121);
    push_stack(test_stack, 64);
    TEST_ASSERT_EQUAL(64, peek_stack(test_stack));
}

void test_stack_is_full() {
    struct Stack* test_stack = create_stack(5);
    push_stack(test_stack, 2);
    push_stack(test_stack, 56121);
    push_stack(test_stack, 64);
    push_stack(test_stack, 841);
    push_stack(test_stack, 0);
    TEST_ASSERT_TRUE(is_stack_full(test_stack));
    TEST_ASSERT_FALSE(is_stack_empty(test_stack));
    free_stack(test_stack);
}

void test_stack_isnt_full() {
    struct Stack* test_stack = create_stack(5);
    push_stack(test_stack, 0);
    TEST_ASSERT_FALSE(is_stack_empty(test_stack));
    TEST_ASSERT_FALSE(is_stack_full(test_stack));
    free_stack(test_stack);
}

void test_stack_is_empty() {
    struct Stack* test_stack = create_stack(5);
    TEST_ASSERT_TRUE(is_stack_empty(test_stack));
    TEST_ASSERT_FALSE(is_stack_full(test_stack));
    free_stack(test_stack);
}

void test_stack_overflow() {
    struct Stack* test_stack = create_stack(5);
    push_stack(test_stack, 32154);
    push_stack(test_stack, 4);
    push_stack(test_stack, 85761);
    push_stack(test_stack, 6832895);
    push_stack(test_stack, 9);
    push_stack(test_stack, 05);
    TEST_ASSERT_EQUAL(5, peek_stack(test_stack));
    TEST_ASSERT_FALSE(is_stack_full(test_stack));
    free_stack(test_stack);
}

void test_stack_removing_from_empty() {
    struct Stack* test_stack = create_stack(5);
    TEST_ASSERT_EQUAL(INT32_MIN, pop_stack(test_stack));
    free_stack(test_stack);
}

void test_stack_removing_from_not_empty() {
    struct Stack* test_stack = create_stack(5);
    push_stack(test_stack, 32154);
    push_stack(test_stack, 4);
    push_stack(test_stack, 85761);
    push_stack(test_stack, 6832895);
    push_stack(test_stack, 9);
    TEST_ASSERT_EQUAL(9, pop_stack(test_stack));
    TEST_ASSERT_EQUAL(6832895, peek_stack(test_stack));
    free_stack(test_stack);
}

void setUp()
{

}

void tearDown()
{

}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_stack_push);
    RUN_TEST(test_stack_is_full);
    RUN_TEST(test_stack_isnt_full);
    RUN_TEST(test_stack_is_empty);
    RUN_TEST(test_stack_overflow);
    RUN_TEST(test_stack_removing_from_empty);
    RUN_TEST(test_stack_removing_from_not_empty);
    UNITY_END();

    return 0;
}
