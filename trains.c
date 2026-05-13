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
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}
void enqueue(Queue *q, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}
int dequeue(Queue *q, Train *removed) {
    if (q->front == NULL) return 0;

    Node *temp = q->front;
    *removed = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    q->size--;
    return 1;
}
void displayQueue(const Queue *q) {
    Node *current = q->front;
    int position = 1;

    if (!current) {
        printf("Queue is empty.\n");
        return;
    }

    while (current) {
        printf("Position %d:\n", position++);
        printTrain(&current->data);
        current = current->next;
    }
}
Node *searchQueueByPosition(const Queue *q, int position) {
    Node *current = q->front;
    int index = 1;
    while (current) {
        if (index == position) return current;
        current = current->next;
        index++;
    }

    return NULL;
}
Node *searchQueueByNumber(const Queue *q, int number) {
    Node *current = q->front;
    while (current) {
        if (current->data.number == number) return current;
        current = current->next;
    }
    return NULL;
}
int deleteQueueByPosition(Queue *q, int position) {
    if (q->front == NULL || position < 1) return 0;

    Node *current = q->front;
    Node *previous = NULL;
    int index = 1;

    while (current && index < position) {
        previous = current;
        current = current->next;
        index++;
    }

    if (!current) return 0;

    if (previous == NULL) {
        q->front = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == q->rear) {
        q->rear = previous;
    }

    free(current);
    q->size--;
    return 1;
}
void clearQueue(Queue *q) {
    Train removed;
    while (dequeue(q, &removed)) {}
}

// Double Ended Queue functions
void initDeque(Deque *dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
}
void insertFrontDeque(Deque *dq, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;
    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front = newNode;
    }
    dq->size++;
}
void insertRearDeque(Deque *dq, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}
int deleteFrontDeque(Deque *dq, Train *removed) {
    if (dq->front == NULL) return 0;
    Node *temp = dq->front;
    *removed = temp->data;
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    free(temp);
    dq->size--;
    return 1;
}
int deleteRearDeque(Deque *dq, Train *removed) {
    if (dq->rear == NULL) return 0;
    Node *current = dq->front;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    *removed = current->data;
    if (previous == NULL) {
        dq->front = dq->rear = NULL;
    } else {
        previous->next = NULL;
        dq->rear = previous;
    }
    free(current);
    dq->size--;
    return 1;
}
void displayDeque(const Deque *dq) {
    Node *current = dq->front;
    int position = 1;
    if (!current) {
        printf("Deque is empty.\n");
        return;
    }
    while (current) {
        printf("Position %d:\n", position++);
        printTrain(&current->data);
        current = current->next;
    }
}
Node *searchDequeByNumber(const Deque *dq, int number) {
    Node *current = dq->front;
    while (current) {
        if (current->data.number == number) return current;
        current = current->next;
    }
    return NULL;
}
int deleteDequeByPosition(Deque *dq, int position) {
    if (dq->front == NULL || position < 1) return 0;
    Node *current = dq->front;
    Node *previous = NULL;
    int index = 1;
    while (current && index < position) {
        previous = current;
        current = current->next;
        index++;
    }
    if (!current) return 0;
    if (previous == NULL) {
        dq->front = current->next;
    } else {
        previous->next = current->next;
    }
    if (current == dq->rear) {
        dq->rear = previous;
    }
    free(current);
    dq->size--;
    return 1;
}
void clearDeque(Deque *dq) {
    Train removed;
    while (deleteFrontDeque(dq, &removed)) {}
}

// Circular Queue functions
void initCircularQueue(CircularQueue *cq) {
    cq->front = NULL;
    cq->rear = NULL;
    cq->size = 0;
}
void enqueueCircular(CircularQueue *cq, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;
    if (cq->front == NULL) {
        cq->front = cq->rear = newNode;
        newNode->next = cq->front;
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
        cq->rear->next = cq->front;
    }
    cq->size++;
}
int dequeueCircular(CircularQueue *cq, Train *removed) {
    if (cq->front == NULL) return 0;
    Node *temp = cq->front;
    *removed = temp->data;
    if (cq->front == cq->rear) {
        cq->front = cq->rear = NULL;
    } else {
        cq->front = cq->front->next;
        cq->rear->next = cq->front;
    }
    free(temp);
    cq->size--;
    return 1;
}
void displayCircularQueue(const CircularQueue *cq) {
    if (cq->front == NULL) {
        printf("Circular Queue is empty.\n");
        return;
    }
    Node *current = cq->front;
    int position = 1;
    do {
        printf("Position %d:\n", position++);
        printTrain(&current->data);
        current = current->next;
    } while (current != cq->front);
}
Node *searchCircularByNumber(const CircularQueue *cq, int number) {
    if (cq->front == NULL) return NULL;
    Node *current = cq->front;
    do {
        if (current->data.number == number) return current;
        current = current->next;
    } while (current != cq->front);
    return NULL;
}
int deleteCircularByPosition(CircularQueue *cq, int position) {
    if (cq->front == NULL || position < 1 || position > cq->size) return 0;
    Node *current = cq->front;
    Node *previous = cq->rear;
    int index = 1;
    while (index < position) {
        previous = current;
        current = current->next;
        index++;
    }
    if (current == cq->front && current == cq->rear) {
        cq->front = cq->rear = NULL;
    } else {
        previous->next = current->next;
        if (current == cq->front) {
            cq->front = current->next;
            cq->rear->next = cq->front;
        }
        if (current == cq->rear) {
            cq->rear = previous;
            cq->rear->next = cq->front;
        }
    }
    free(current);
    cq->size--;
    return 1;
}
void clearCircularQueue(CircularQueue *cq) {
    Train removed;
    while (dequeueCircular(cq, &removed)) {}
}

// Priority Queue functions
void initPriorityQueue(PriorityQueue *pq) {
    pq->front = NULL;
    pq->size = 0;
}
static int trainPriority(Train t) {
    int depTime = t.dep_hour * 60 + t.dep_min;
    return t.circulation * 10000 + depTime;
}
void enqueuePriority(PriorityQueue *pq, Train train) {
    Node *newNode = createNode(train);
    if (!newNode) return;
    if (pq->front == NULL || trainPriority(train) < trainPriority(pq->front->data)) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node *current = pq->front;
        while (current->next != NULL &&
               trainPriority(current->next->data) <= trainPriority(train)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    pq->size++;
}
int dequeuePriority(PriorityQueue *pq, Train *removed) {
    if (pq->front == NULL) return 0;
    Node *temp = pq->front;
    *removed = temp->data;
    pq->front = pq->front->next;
    free(temp);
    pq->size--;
    return 1;
}
void displayPriorityQueue(const PriorityQueue *pq) {
    Node *current = pq->front;
    int position = 1;
    if (!current) {
        printf("Priority Queue is empty.\n");
        return;
    }
    while (current) {
        printf("Priority position %d:\n", position++);
        printTrain(&current->data);
        current = current->next;
    }
}
Node *searchPriorityByNumber(const PriorityQueue *pq, int number) {
    Node *current = pq->front;
    while (current) {
        if (current->data.number == number) return current;
        current = current->next;
    }
    return NULL;
}
int deletePriorityByPosition(PriorityQueue *pq, int position) {
    if (pq->front == NULL || position < 1) return 0;
    Node *current = pq->front;
    Node *previous = NULL;
    int index = 1;
    while (current && index < position) {
        previous = current;
        current = current->next;
        index++;
    }
    if (!current) return 0;
    if (previous == NULL) {
        pq->front = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    pq->size--;
    return 1;
}
void clearPriorityQueue(PriorityQueue *pq) {
    Train removed;
    while (dequeuePriority(pq, &removed)) {}
}

// File functions
void readFilePath(char *path, int size) {
    clearInputBuffer();
    printf("Enter full file path/name: ");
    fgets(path, size, stdin);
    path[strcspn(path, "\n")] = '\0';
}
static void saveListTxt(Node *start, const char *path, int circular) {
    FILE *file = fopen(path, "w");
    if (!file) {
        printf("Cannot open file.\n");
        return;
    }
    if (!start) {
        fprintf(file, "List is empty.\n");
        fclose(file);
        return;
    }
    Node *current = start;
    if (!circular) {
        while (current) {
            printTrainToFile(file, &current->data);
            current = current->next;
        }
    } else {
        do {
            printTrainToFile(file, &current->data);
            current = current->next;
        } while (current != start);
    }
    fclose(file);
    printf("Saved successfully in text file.\n");
}
static void saveListBinary(Node *start, const char *path, int circular) {
    FILE *file = fopen(path, "wb");
    if (!file) {
        printf("Cannot open binary file.\n");
        return;
    }
    if (!start) {
        fclose(file);
        return;
    }
    Node *current = start;
    if (!circular) {
        while (current) {
            fwrite(&current->data, sizeof(Train), 1, file);
            current = current->next;
        }
    } else {
        do {
            fwrite(&current->data, sizeof(Train), 1, file);
            current = current->next;
        } while (current != start);
    }
    fclose(file);
    printf("Saved successfully in binary file.\n");
}
void saveStackTxt(const Stack *s, const char *path) {
    saveListTxt(s->top, path, 0);
}
void saveQueueTxt(const Queue *q, const char *path) {
    saveListTxt(q->front, path, 0);
}
void saveDequeTxt(const Deque *dq, const char *path) {
    saveListTxt(dq->front, path, 0);
}
void saveCircularTxt(const CircularQueue *cq, const char *path) {
    saveListTxt(cq->front, path, 1);
}
void savePriorityTxt(const PriorityQueue *pq, const char *path) {
    saveListTxt(pq->front, path, 0);
}
void saveStackBinary(const Stack *s, const char *path) {
    saveListBinary(s->top, path, 0);
}
void saveQueueBinary(const Queue *q, const char *path) {
    saveListBinary(q->front, path, 0);
}
void saveDequeBinary(const Deque *dq, const char *path) {
    saveListBinary(dq->front, path, 0);
}
void saveCircularBinary(const CircularQueue *cq, const char *path) {
    saveListBinary(cq->front, path, 1);
}
void savePriorityBinary(const PriorityQueue *pq, const char *path) {
    saveListBinary(pq->front, path, 0);
}
void readTextFile(const char *path) {
    FILE *file = fopen(path, "r");
    char line[256];
    if (!file) {
        printf("Cannot open file for reading.\n");
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
void deleteFileByPath(const char *path) {
    if (remove(path) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Could not delete file.\n");
    }
}