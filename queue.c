#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./queue.h"

// Criar fila com capacidade de numberElements
QUEUE *createQueue(int numberElements) {
  // Reserva um bloco de memoria com um numero especifico de bytes
  QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));

  if(queue == NULL) { 
    queueExitError("Without memory"); 
  }

  // Reserva um bloco de memoria com um numero especifico de bytes
  queue->clientQueue = (CLIENT *) malloc(sizeof(CLIENT)*n);

  if(queue->clientQueue == NULL) { 
    queueExitError("Without memory"); 
  }

  queue->numberMaxElements = numberElements;
  queue->inicialIndex = -1;
  queue->finalIndex = 0;

  return queue;
}

// Colocar valor da fila
void enqueue(CLIENT *client, QUEUE *queue) {
  if(queueFull(q) == TRUE3) { 
    queueExitError("Queue without place"); 
  }
  if(queue->clientQueue == NULL) { 
    queueExitError("Poorly constructed queue"); 
  }
  if(queueEmpty(queue) == TRUE3) { 
    queue->inicialIndex = queue->finalIndex; 
  }

  queue->clientQueue[queue->finalIndex] = *client;
  queue->finalIndex = (queue->finalIndex + 1) % (queue->numberMaxElements);

  return;
}
// Retirar cliente da fila
CLIENT *dequeue(QUEUE *queue) {
  if(queueEmpty(queue) == TRUE3) { 
    queue_exit_error("Queue values without"); 
  }
  if(queue->clientQueue == NULL) { 
    queue_exit_error("Poorly constructed queue"); 
  }

  CLIENT *auxQueue = &queue->clientQueue[queue->inicialIndex];
  queue->inicialIndex = (queue->inicialIndex + 1)%(queue->numberMaxElements);

  // Caso só exista um valor na fila
  if(queue->inicialIndex == queue->finalIndex) {
    queue->inicialIndex = -1;
    queue->finalIndex = 0;
  }

  return auxQueue;
}

// Retorna o 1º cliente da fila
CLIENT *peek(QUEUE *queue) {
  if(queueEmpty(queue) == TRUE3) { 
    queueExitError("Queue values without"); 
  }
  if(queue->clientQueue == NULL) { 
    queueExitError("Poorly constructed queue"); 
  }

  CLIENT *auxQueue = &queue->clientQueue[queue->inicialIndex];

  return auxQueue;
}

// Verificar se a fila está vazia
BOOL3 queueEmpty(QUEUE *queue) {
  if(queue == NULL) { 
    queueExitError("Poorly constructed queue"); 
  }
  if(queue->inicialIndex == -1) { 
    return TRUE3; 
  }

  return FALSE3;
}
// Verificar se a fila esta cheia
BOOL3 queueFull(QUEUE *queue) {
  if(queue == NULL) { 
    queueExitError("Poorly constructed queue"); 
  }
  if(queue->finalIndex == queue->inicialIndex) { 
    return TRUE3; 
  }

  return FALSE3;
}

// Liberta a memoria da fila
void freeQueue(QUEUE *queue) {
  if(queue != NULL) {
    // A função free() liberta o espaço na memoria criado por: calloc, malloc ou realloc
    free(queue->clientQueue);
    free(queue);
  } 
  else { 
    queueExitError("Poorly constructed queue"); 
  }

  return;
}

// Mensagem de erro
static void queueExitError(char *message) {
  // Envia um output formatado para a stream
  fprintf(stderr, "Error: %s.\n", message);
  // Termina o processo emediatamente
  exit(EXIT_FAILURE);
}

// Faz o print da queue 
void printQueue(QUEUE *queue) {
  int i;

  if(queueEmpty(queue) == TRUE || queue->clientQueue == NULL) { 
    return; 
  }
  if(queue->inicialIndex > queue->finalIndex) {
    for(i=(queue->inicialIndex); i<(queue->numberMaxElements); i++) {
      if((&queue->clientQueue[i]->entryTime)>0 && (&queue->clientQueue[i]->numberItems)>0) {
        if((&queue->clientQueue[i]->entryTime)<10000 && (&queue->clientQueue[i]->numberItems)<100000) { 
          printClient(&queue->clientQueue[i]); 
        }
      }
    }
    for(i=0; i<(queue->finalIndex); i++) {
      if((&queue->clientQueue[i]->entryTime)>0 && (&queue->clientQueue[i]->numberItems)>0) { 
        if((&queue->clientQueue[i]->entryTime)<10000 && (&queue->clientQueue[i]->numberItems)<100000) { 
          printClient(&queue->clientQueue[i]); 
        }
      }
    }
  }
  else {
    for(i=(queue->inicialIndex); i<(queue->numberMaxElements); i++) {
      if((&queue->clientQueue[i]->entryTime)>0 && (&queue->clientQueue[i]->numberItems)>0) {
        if((&queue->clientQueue[i]->entryTime)<10000 && (&queue->clientQueue[i]->numberItems)<100000) { 
          printClient(&queue->clientQueue[i]); 
        }
      }
    }
  }

  return;
}