#include "trains.h"
#include <stdlib.h>
#include <string.h>

void clearInputBuffer(void) {

}
const char *circulationName(int circulation) {

}
Train inputTrain(void) {

}
void printTrain(const Train *t) {

}
void printTrainToFile(FILE *file, const Train *t) {

}
Node *createNode(Train train) {

}

// Stack functions
void initStack(Stack *s) {

}
void pushStack(Stack *s, Train train) {

}
int popStack(Stack *s, Train *removed) {

}
void displayStack(const Stack *s) {

}
Node *searchStackByPosition(const Stack *s, int position) {

}
Node *searchStackByNumber(const Stack *s, int number) {

}
int deleteStackByPosition(Stack *s, int position) {

}
void clearStack(Stack *s) {

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