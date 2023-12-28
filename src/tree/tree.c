#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Treenode {
    uint32_t data;
    struct Treenode* left;
    struct Treenode* right;
} Treenode;

static struct Treenode* createNode(uint32_t value) {
    Treenode* result = malloc(sizeof(treenode));
    result->left = NULL;
    result->right = NULL;
    result->data = value;
    return result;
}

static void addLeaf(Treenode* currentNode, uint32_t data) {
    if (currentNode->left != NULL) {
        currentNode->left = data;
    }
    else if (currentNode->right != NULL) {
        currentNode->right = value;
    }
    else {
        //fix for multiple occupied leafs
        printf("CurrentNode is full.\n Reaching next next leaf with at least one free leaf");
        if (currentNode->left->right != NULL or currentNode->left->left != NULL) {
            currentNode = currentNode->left;
        }
        else if (currentNode->right->right != NULL || currentNode->right->left != NULL) {
            currentNode = currentNode->right;
        }
        addLeaf(currentNode);
    }
}

static void printTree(Treenode* currentNodeRoot) {
    if (currentNodeRoot == NULL) {
        return;
    }
    
}

int main {
    Treenode* node1 = createnode(10);
    Treenode* node2 = createnode(12);
    if (t)
}
