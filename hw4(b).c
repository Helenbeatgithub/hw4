/******************************************************************************
Part 2 : Linked List Priority Queue

Write a C program to implement a "Linked List Priority Queue". The program should contain the following functions:

1. Enqueue - to insert values in the queue. Make sure the new node is inserted in the correct place according to it's priority value.

2. Dequeue - to delete values from the priority queue. Delete the head node (node with the highest priority). 

3. isEmpty - To check if the queue is empty

4. isFull - To check if the queue is full

Priority queue should be implemented using Linked Lists. The structure should contain data (int), priority (int) and next Node.

NOTE: Priority with LOWER value will come FIRST. E.g. Node with priority 2 will come before node with priority 4. 

All of the above functions should be in a do while loop and the input should be taken from the user. 

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* newNode(int data, int priority) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

int isFull(int size) {
    return size == MAX_SIZE;
}

void enqueue(Node** head, int data, int priority, int* size) {
    Node* start = (*head);
    Node* temp = newNode(data, priority);

    if (isFull(*size)) {
        printf("Queue is full\n");
        return;
    }

    if ((*head)->priority > priority) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < priority) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }

    (*size)++;
}

void dequeue(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

int main() {
    Node* pq = newNode(-1, -1);
    int size = 0;
    int choice;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Check if Empty\n4. Check if Full\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data and priority: ");
                int data, priority;
                scanf("%d %d", &data, &priority);
                enqueue(&pq, data, priority, &size);
                break;
            case 2:
                if(!isEmpty(&pq)) {
                    dequeue(&pq);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                if(isEmpty(&pq)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                if(isFull(size)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

