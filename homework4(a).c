/******************************************************************************
Part 1:  Binary Search Trees

Write a C program for the following question. 

Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.

Hint: Use a modified version of binary search. 
If the target is less than the current node value, go left, otherwise go right. 
At each point calculate the closest value to the target. 

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define structure for BST nodes
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new BST node
Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key in BST
Node* insert(Node* node, int key) {
    // If the tree is empty, assign a new node address to the root
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

// Helper function that finds the value in a BST that is closest to the target
void findClosest(Node* node, double target, double* closest) {
    if (node == NULL) {
        return;
    }

    if (fabs(node->key - target) < fabs(*closest - target)) {
        *closest = node->key;
    }

    if (target < node->key) {
        findClosest(node->left, target, closest);
    } else if (target > node->key) {
        findClosest(node->right, target, closest);
    } else {
        return;
    }
}

int main() {
    Node* root = NULL;
    int n, i, key;
    double target, closest;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the keys: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        if (i == 0)
            root = insert(root, key);
        else
            insert(root, key);
    }

    printf("Enter the target value: ");
    scanf("%lf", &target);

    closest = root->key;
    findClosest(root, target, &closest);

    printf("Closest number = %.2lf\n", closest);

    return 0;
}
