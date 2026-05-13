#include <stdio.h>
#include "trains.h"

void stackMenu(Stack *stack) {
    int choice, position, number;
    Train train;
    Node *found;
    char path[200];
    do {
        printf("\n STACK MENU \n");
        printf("1. Push train\n");
        printf("2. Pop train\n");
        printf("3. Display stack\n");
        printf("4. Search by position\n");
        printf("5. Search by train number\n");
        printf("6. Delete by position\n");
        printf("7. Save to TXT\n");
        printf("8. Save to binary\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train = inputTrain();
                pushStack(stack, train);
                break;
            case 2:
                if (popStack(stack, &train)) {
                    printf("Removed train:\n");
                    printTrain(&train);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                printf("Position: ");
                scanf("%d", &position);
                found = searchStackByPosition(stack, position);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 5:
                printf("Train number: ");
                scanf("%d", &number);
                found = searchStackByNumber(stack, number);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 6:
                printf("Position to delete: ");
                scanf("%d", &position);
                if (deleteStackByPosition(stack, position)) printf("Deleted.\n");
                else printf("Invalid position.\n");
                break;
            case 7:
                readFilePath(path, sizeof(path));
                saveStackTxt(stack, path);
                break;
            case 8:
                readFilePath(path, sizeof(path));
                saveStackBinary(stack, path);
                break;
        }
    } while (choice != 0);
}
void simpleQueueMenu(Queue *queue) {
    int choice, position, number;
    Train train;
    Node *found;
    char path[200];
    do {
        printf("\n SIMPLE QUEUE MENU \n");
        printf("1. Enqueue train\n");
        printf("2. Dequeue train\n");
        printf("3. Display queue\n");
        printf("4. Search by position\n");
        printf("5. Search by train number\n");
        printf("6. Delete by position\n");
        printf("7. Save to TXT\n");
        printf("8. Save to binary\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train = inputTrain();
                enqueue(queue, train);
                break;
            case 2:
                if (dequeue(queue, &train)) {
                    printf("Removed train:\n");
                    printTrain(&train);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Position: ");
                scanf("%d", &position);
                found = searchQueueByPosition(queue, position);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 5:
                printf("Train number: ");
                scanf("%d", &number);
                found = searchQueueByNumber(queue, number);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 6:
                printf("Position to delete: ");
                scanf("%d", &position);
                if (deleteQueueByPosition(queue, position)) printf("Deleted.\n");
                else printf("Invalid position.\n");
                break;
            case 7:
                readFilePath(path, sizeof(path));
                saveQueueTxt(queue, path);
                break;
            case 8:
                readFilePath(path, sizeof(path));
                saveQueueBinary(queue, path);
                break;
        }
    } while (choice != 0);
}
void dequeMenu(Deque *deque) {
    int choice, position, number;
    Train train;
    Node *found;
    char path[200];
    do {
        printf("\n DOUBLE ENDED QUEUE MENU \n");
        printf("1. Insert front\n");
        printf("2. Insert rear\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Display deque\n");
        printf("6. Search by train number\n");
        printf("7. Delete by position\n");
        printf("8. Save to TXT\n");
        printf("9. Save to binary\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train = inputTrain();
                insertFrontDeque(deque, train);
                break;
            case 2:
                train = inputTrain();
                insertRearDeque(deque, train);
                break;
            case 3:
                if (deleteFrontDeque(deque, &train)) printTrain(&train);
                else printf("Deque is empty.\n");
                break;
            case 4:
                if (deleteRearDeque(deque, &train)) printTrain(&train);
                else printf("Deque is empty.\n");
                break;
            case 5:
                displayDeque(deque);
                break;
            case 6:
                printf("Train number: ");
                scanf("%d", &number);
                found = searchDequeByNumber(deque, number);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 7:
                printf("Position to delete: ");
                scanf("%d", &position);
                if (deleteDequeByPosition(deque, position)) printf("Deleted.\n");
                else printf("Invalid position.\n");
                break;
            case 8:
                readFilePath(path, sizeof(path));
                saveDequeTxt(deque, path);
                break;
            case 9:
                readFilePath(path, sizeof(path));
                saveDequeBinary(deque, path);
                break;
        }
    } while (choice != 0);
}
void circularQueueMenu(CircularQueue *cq) {
    int choice, position, number;
    Train train;
    Node *found;
    char path[200];
    do {
        printf("\n CIRCULAR QUEUE MENU \n");
        printf("1. Enqueue train\n");
        printf("2. Dequeue train\n");
        printf("3. Display circular queue\n");
        printf("4. Search by train number\n");
        printf("5. Delete by position\n");
        printf("6. Save to TXT\n");
        printf("7. Save to binary\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train = inputTrain();
                enqueueCircular(cq, train);
                break;
            case 2:
                if (dequeueCircular(cq, &train)) printTrain(&train);
                else printf("Circular Queue is empty.\n");
                break;
            case 3:
                displayCircularQueue(cq);
                break;
            case 4:
                printf("Train number: ");
                scanf("%d", &number);
                found = searchCircularByNumber(cq, number);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 5:
                printf("Position to delete: ");
                scanf("%d", &position);
                if (deleteCircularByPosition(cq, position)) printf("Deleted.\n");
                else printf("Invalid position.\n");
                break;
            case 6:
                readFilePath(path, sizeof(path));
                saveCircularTxt(cq, path);
                break;
            case 7:
                readFilePath(path, sizeof(path));
                saveCircularBinary(cq, path);
                break;
        }
    } while (choice != 0);
}
void priorityQueueMenu(PriorityQueue *pq) {
    int choice, position, number;
    Train train;
    Node *found;
    char path[200];
    do {
        printf("\n PRIORITY QUEUE MENU \n");
        printf("1. Insert train by priority\n");
        printf("2. Delete highest priority train\n");
        printf("3. Display priority queue\n");
        printf("4. Search by train number\n");
        printf("5. Delete by position\n");
        printf("6. Save to TXT\n");
        printf("7. Save to binary\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train = inputTrain();
                enqueuePriority(pq, train);
                break;
            case 2:
                if (dequeuePriority(pq, &train)) printTrain(&train);
                else printf("Priority Queue is empty.\n");
                break;
            case 3:
                displayPriorityQueue(pq);
                break;
            case 4:
                printf("Train number: ");
                scanf("%d", &number);
                found = searchPriorityByNumber(pq, number);
                if (found) printTrain(&found->data);
                else printf("Not found.\n");
                break;
            case 5:
                printf("Position to delete: ");
                scanf("%d", &position);
                if (deletePriorityByPosition(pq, position)) printf("Deleted.\n");
                else printf("Invalid position.\n");
                break;
            case 6:
                readFilePath(path, sizeof(path));
                savePriorityTxt(pq, path);
                break;
            case 7:
                readFilePath(path, sizeof(path));
                savePriorityBinary(pq, path);
                break;
        }
    } while (choice != 0);
}
void fileMenu(void) {
    int choice;
    char path[200];
    do {
        printf("\n FILE MENU \n");
        printf("1. Open and read TXT file\n");
        printf("2. Delete file\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readFilePath(path, sizeof(path));
                readTextFile(path);
                break;
            case 2:
                readFilePath(path, sizeof(path));
                deleteFileByPath(path);
                break;
        }
    } while (choice != 0);
}
int main(void) {
    Stack stack;
    Queue queue;
    Deque deque;
    CircularQueue circularQueue;
    PriorityQueue priorityQueue;

    int choice;

    initStack(&stack);
    initQueue(&queue);
    initDeque(&deque);
    initCircularQueue(&circularQueue);
    initPriorityQueue(&priorityQueue);
    do {
        printf("\n TRAIN ADS MAIN MENU \n");
        printf("1. Dynamic Stack based on linked list\n");
        printf("2. Simple Queue based on linked list\n");
        printf("3. Double Ended Queue based on linked list\n");
        printf("4. Circular Queue based on linked list\n");
        printf("5. Priority Queue based on linked list\n");
        printf("6. File operations\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                stackMenu(&stack);
                break;
            case 2:
                simpleQueueMenu(&queue);
                break;
            case 3:
                dequeMenu(&deque);
                break;
            case 4:
                circularQueueMenu(&circularQueue);
                break;
            case 5:
                priorityQueueMenu(&priorityQueue);
                break;
            case 6:
                fileMenu();
                break;
            case 0:
                printf("Program finished.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 0);
    clearStack(&stack);
    clearQueue(&queue);
    clearDeque(&deque);
    clearCircularQueue(&circularQueue);
    clearPriorityQueue(&priorityQueue);
    return 0;
}