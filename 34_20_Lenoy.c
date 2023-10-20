/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 27.09.2023
Desription: Linked List Implementation of Priority Queue
*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the Priority Queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node with given data and priority
struct Node* newNode(int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        perror("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to insert an element with a given priority into the Priority Queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* new_node = newNode(data, priority);

    // If the queue is empty or the new node has a higher priority, insert it at the beginning
    if (*head == NULL || priority < (*head)->priority) {
        new_node->next = *head;
        *head = new_node;
    } else {
        // Find the correct position to insert the new node
        struct Node* current = *head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to remove and return the element with the highest priority from the Priority Queue
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        exit(EXIT_FAILURE);
    } else {
        struct Node* temp = *head;
        int data = temp->data;
        *head = (*head)->next;
        free(temp);
        return data;
    }
}

// Function to check if the Priority Queue is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to display the elements in the Priority Queue
void displayQueue(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements:\n");
    while (head != NULL) {
        printf("Priority: %d, Data: %d\n", head->priority, head->data);
        head = head->next;
    }
}

int main() {
    struct Node* priorityQueue = NULL;
    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&priorityQueue, data, priority);
                break;
            case 2:
                if (!isEmpty(priorityQueue)) {
                    printf("Dequeued element with priority %d: %d\n", priorityQueue->priority, dequeue(&priorityQueue));
                }
                break;
            case 3:
                displayQueue(priorityQueue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    while (!isEmpty(priorityQueue)) {
        dequeue(&priorityQueue);
    }

    return 0;
}