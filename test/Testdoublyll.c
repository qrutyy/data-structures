#include <stddef.h>
#include <stdlib.h>
#include "unity.h"
#include "sharedheader.h"

// char* read_stdin() {
//     char* buffer = (char*)malloc(100); // Allocate memory on the heap
//     if (buffer == NULL) {
//         fprintf(stderr, "Memory allocation failed\n");
//         exit(EXIT_FAILURE);
//     }
//     fgets(buffer, 100, stdin);
//     return buffer;
// }

void test_dlist_push() {
    struct Node* head = NULL;
    push_dlist_beginning(&head, 5);
    push_dlist_beginning(&head, 6);
    push_dlist_beginning(&head, 7);
    push_dlist_beginning(&head, 8);
    push_dlist_beginning(&head, 9);

    TEST_ASSERT_EQUAL(9, peek_dlist_head(head));
    TEST_ASSERT_EQUAL(5, peek_dlist_tail(head));
    free_dlist(&head);
}

void test_dlist_is_empty() {
    struct Node* head = NULL;
    TEST_ASSERT_TRUE(is_dlist_empty(head));
    free_dlist(&head);
}

void test_dlist_isnt_empty() {
    struct Node* head = NULL;
    push_dlist_beginning(&head, 9);

    TEST_ASSERT_FALSE(is_dlist_empty(head));
    free_dlist(&head);
}

void test_dlist_remove_value() {
    struct Node* head = NULL;
    push_dlist_beginning(&head, 38129);
    push_dlist_end(&head, 89772);
    push_dlist_beginning(&head, 6);
    push_dlist_beginning(&head, 7);
    push_dlist_beginning(&head, 8);
    remove_value_dlist(&head, 38129);

    TEST_ASSERT_EQUAL(8, peek_dlist_head(head));
    remove_value_dlist(&head, 89772);

    TEST_ASSERT_EQUAL(6, peek_dlist_tail(head));
    TEST_ASSERT_EQUAL(8, pop_dlist(&head));
    free_dlist(&head);
}

// void test_dlist_print() {
//     struct Node* head = NULL;
//     push_dlist_beginning(&head, 65348);
//     push_dlist_end(&head, 851984820);
//     push_dlist_beginning(&head, 0);
//     push_dlist_beginning(&head, 432975);
//     push_dlist_beginning(&head, 677777729);
//     remove_value_dlist(&head, 65348);
//     print_dlist_forward(head);

//     // // char* result = read_stdin();
//     // TEST_ASSERT_EQUAL_MEMORY("Doubly Linked List (Backward): 67777772 -> 432975 -> 0 -> 65348 -> 851984820", stdin, 77);
//     free_dlist(&head);
// }

void setUp() {

}

void tearDown() {

}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_dlist_push);
    RUN_TEST(test_dlist_is_empty);
    RUN_TEST(test_dlist_isnt_empty);
    RUN_TEST(test_dlist_remove_value);
    // RUN_TEST(test_dlist_print);
    UNITY_END();

    return 0;
}