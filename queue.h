#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./client.c"

typedef enum {FALSE3,TRUE3} BOOL3;

typedef struct fila {
  int inicialIndex;
  int finalIndex;
  int numberMaxElements;
  CLIENT *clientQueue;
} QUEUE;

QUEUE *createQueue(int numberElements);
void enqueue(CLIENT *client, QUEUE *queue);
CLIENT *dequeue(QUEUE *queue);
CLIENT *peek(QUEUE *queue);
BOOL3 queueEmpty(QUEUE *queue);
BOOL3 queueFull(QUEUE *queue);
void freeQueue(QUEUE *queue);
static void queueExitError(char *message);
void printQueue(QUEUE *queue);
