#include <stddef.h>
#include "unity.h"
#include "sharedheader.h"

void test_slist_push() {
    struct Node* head = NULL;
    push_slist_beginning(&head, 5);
    push_slist_beginning(&head, 6);
    push_slist_beginning(&head, 7);
    push_slist_beginning(&head, 8);
    push_slist_beginning(&head, 9);
    TEST_ASSERT_EQUAL(9, peek_slist_head(head));
    TEST_ASSERT_EQUAL(5, peek_slist_tail(head));
    free_slist(&head);
}

void test_slist_is_empty() {
    struct Node* head = NULL;
    TEST_ASSERT_TRUE(is_slist_empty(head));
    free_slist(&head);
}

void test_slist_isnt_empty() {
    struct Node* head = NULL;
    push_slist_beginning(&head, 9);
    TEST_ASSERT_FALSE(is_slist_empty(head));
    free_slist(&head);
}

void test_remove_value() {
    struct Node* head = NULL;
    push_slist_beginning(&head, 38129);
    push_slist_end(&head, 89772);
    push_slist_beginning(&head, 6);
    push_slist_beginning(&head, 7);
    push_slist_beginning(&head, 8);
    remove_value_slist(&head, 38129);
    TEST_ASSERT_EQUAL(8, peek_slist_head(head));
    remove_value_slist(&head, 89772);
    TEST_ASSERT_EQUAL(6, peek_slist_tail(head));
    TEST_ASSERT_EQUAL(8, pop_slist(&head));
    free_slist(&head);
}

void setUp() {

}

void tearDown() {

}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_slist_push);
    RUN_TEST(test_slist_is_empty);
    RUN_TEST(test_slist_isnt_empty);
    RUN_TEST(test_remove_value);
    UNITY_END();

    return 0;
}