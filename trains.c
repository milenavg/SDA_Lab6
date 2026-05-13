#include "trains.h"
#include <stdlib.h>
#include <string.h>

// General function
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
const char *circulationName(int circulation) {
    switch (circulation) {
        case DAILY: return "Daily";
        case ODD: return "Odd days";
        case EVEN: return "Even days";
        default: return "Unknown";
    }
}
Train inputTrain(void) {
    Train t;

    printf("Train number: ");
    scanf("%d", &t.number);
    clearInputBuffer();

    printf("Destination: ");
    fgets(t.destination, sizeof(t.destination), stdin);
    t.destination[strcspn(t.destination, "\n")] = '\0';

    printf("Departure hour and minute: ");
    scanf("%d %d", &t.dep_hour, &t.dep_min);

    printf("Arrival hour and minute: ");
    scanf("%d %d", &t.arr_hour, &t.arr_min);

    printf("Circulation: 0-Daily, 1-Odd, 2-Even: ");
    scanf("%d", &t.circulation);

    return t;
}
void printTrain(const Train *t) {
    printf("Train number: %d\n", t->number);
    printf("Destination: %s\n", t->destination);
    printf("Departure: %02d:%02d\n", t->dep_hour, t->dep_min);
    printf("Arrival: %02d:%02d\n", t->arr_hour, t->arr_min);
    printf("Circulation: %s\n\n", circulationName(t->circulation));
}
void printTrainToFile(FILE *file, const Train *t) {
    fprintf(file, "Train number: %d\n", t->number);
    fprintf(file, "Destination: %s\n", t->destination);
    fprintf(file, "Departure: %02d:%02d\n", t->dep_hour, t->dep_min);
    fprintf(file, "Arrival: %02d:%02d\n", t->arr_hour, t->arr_min);
    fprintf(file, "Circulation: %s\n\n", circulationName(t->circulation));
}
Node *createNode(Train train) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = train;
    newNode->next = NULL;
    return newNode;
}

// Stack functions
void initStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}
void pushStack(Stack *s, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;

    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}
int popStack(Stack *s, Train *removed) {
    if (s->top == NULL) return 0;

    Node *temp = s->top;
    *removed = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;

    return 1;
}
void displayStack(const Stack *s) {
    Node *current = s->top;
    int position = 1;

    if (!current) {
        printf("Stack is empty.\n");
        return;
    }

    while (current) {
        printf("Position %d:\n", position++);
        printTrain(&current->data);
        current = current->next;
    }
}
Node *searchStackByPosition(const Stack *s, int position) {
    Node *current = s->top;
    int index = 1;

    while (current) {
        if (index == position) return current;
        current = current->next;
        index++;
    }

    return NULL;
}
Node *searchStackByNumber(const Stack *s, int number) {
    Node *current = s->top;

    while (current) {
        if (current->data.number == number) return current;
        current = current->next;
    }

    return NULL;
}
int deleteStackByPosition(Stack *s, int position) {
    if (s->top == NULL || position < 1) return 0;

    Node *current = s->top;
    Node *previous = NULL;
    int index = 1;

    while (current && index < position) {
        previous = current;
        current = current->next;
        index++;
    }

    if (!current) return 0;

    if (previous == NULL) {
        s->top = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    s->size--;
    return 1;
}
void clearStack(Stack *s) {
    Train removed;
    while (popStack(s, &removed)) {}
}

// Simple Queue functions
void initQueue(Queue *q) {

}
void enqueue(Queue *q, Train train) {

}
int dequeue(Queue *q, Train *removed) {

}
void displayQueue(const Queue *q) {

}
Node *searchQueueByPosition(const Queue *q, int position) {

}
Node *searchQueueByNumber(const Queue *q, int number) {

}
int deleteQueueByPosition(Queue *q, int position) {

}
void clearQueue(Queue *q) {

}

// Double Ended Queue functions
void initDeque(Deque *dq) {

}
void insertFrontDeque(Deque *dq, Train train) {

}
void insertRearDeque(Deque *dq, Train train) {

}
int deleteFrontDeque(Deque *dq, Train *removed) {

}
int deleteRearDeque(Deque *dq, Train *removed) {

}
void displayDeque(const Deque *dq) {

}
Node *searchDequeByNumber(const Deque *dq, int number) {

}
int deleteDequeByPosition(Deque *dq, int position) {

}
void clearDeque(Deque *dq) {

}

// Circular Queue functions
void initCircularQueue(CircularQueue *cq) {

}
void enqueueCircular(CircularQueue *cq, Train train) {

}
int dequeueCircular(CircularQueue *cq, Train *removed) {

}
void displayCircularQueue(const CircularQueue *cq) {

}
Node *searchCircularByNumber(const CircularQueue *cq, int number) {

}
int deleteCircularByPosition(CircularQueue *cq, int position) {

}
void clearCircularQueue(CircularQueue *cq) {

}

// Priority Queue functions
void initPriorityQueue(PriorityQueue *pq) {

}
void enqueuePriority(PriorityQueue *pq, Train train) {

}
int dequeuePriority(PriorityQueue *pq, Train *removed) {

}
void displayPriorityQueue(const PriorityQueue *pq) {

}
Node *searchPriorityByNumber(const PriorityQueue *pq, int number) {

}
int deletePriorityByPosition(PriorityQueue *pq, int position) {

}
void clearPriorityQueue(PriorityQueue *pq) {

}

// File functions
void readFilePath(char *path, int size) {

}
void saveStackTxt(const Stack *s, const char *path) {

}
void saveQueueTxt(const Queue *q, const char *path) {

}
void saveDequeTxt(const Deque *dq, const char *path) {

}
void saveCircularTxt(const CircularQueue *cq, const char *path) {

}
void savePriorityTxt(const PriorityQueue *pq, const char *path) {

}

void saveStackBinary(const Stack *s, const char *path) {

}
void saveQueueBinary(const Queue *q, const char *path) {

}
void saveDequeBinary(const Deque *dq, const char *path) {

}
void saveCircularBinary(const CircularQueue *cq, const char *path) {

}
void savePriorityBinary(const PriorityQueue *pq, const char *path) {

}

void readTextFile(const char *path) {

}
void deleteFileByPath(const char *path) {

}