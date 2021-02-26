#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./cashier.h"

// Inicializa
CASHIER *initCashier(int numberCashier) {
  // Reserva um bloco de memoria com um numero especifico de bytes
  CASHIER *cashier = (CASHIER *) malloc(sizeof(CASHIER));

  //Inicializa o gerador de numeros random
  srand(time(0));

  cashier->cashierAvailable = 0;
  cashier->numberServedClients = 0;
  cashier->numberProcessedProducts = 0;
  cashier->numberCashier = numberCashier;
  cashier->waitingTime = 0;
  cashier->productsProcessedPerUnitTime = rand()%5 + 1;
  cashier->clientQueue = createQueue(25);

  return cashier;
}

// Retira um cliente da caixa
void removeClient(CASHIER *cashier) {
  QUEUE *q = cashier->clientQueue;
  dequeue(q);
  cashier->clientQueue = q;

  return;
}

// Verifica se a caixa esta vazia
BOOL2 emptyCashier(CASHIER *cashier) {
  if(queueEmpty(cashier->clientQueue) == FALSE1) { 
    return FALSE2; 
  }

  return TRUE;
}

// Faz print da caixa 
void printCashier(CASHIER *cashier) {
  printf("Cashier %d (%d): <", cashier->numberCashier, cashier->cashierAvailable);
  printQueue(cashier->clientQueue);
  printf(" < \n");

  return;
}

/***** Setters *****/
// Actualiza o numero de clientes atendidos
void setNumberClientsServed(CASHIER *cashier) {
  cashier->numberServedClients = cashier->numberServedClients + 1;

  return;
}
// Actualiza o o numero de produtos processados
void setNumberProcessedProducts(CASHIER *cashier, int clientNumberItems) {
  cashier->numberProcessedProducts = cashier->numberProcessedProducts + clientNumberItems;

  return;
}
// Actualiza o tempo de espera
void setWaitingTime(CASHIER *cashier, int clientEntryTime) {
  cashier->waitingTime = cashier->waitingTime + clientEntryTime;

  return;
}
// Actualiza o instante em que a caixa estara disponivel
void setCashierAvailable(CASHIER *cashier, int cycle) {
  cashier->cashierAvailable = cycle;

  return;
}

/***** Getters *****/
// Devolve o numero da caixa
int getCashierNumber(CASHIER *cashier) { 
  return cashier->numberCashier; 
}
// Devolve o numero de clientes atendidos
int getNumberServedClients(CASHIER *cashier) { 
  return cashier->numberServedClients; 
}
// Devolve o numero de produtos processados
int getNumberProcessedProducts(CASHIER *cashier) { 
  return cashier->numberProcessedProducts; 
}
// Devolve o numero de produtos processados por unidade de tempo
int getProductsProcessedPerUnitTime(CASHIER *cashier) { 
  return cashier->productsProcessedPerUnitTime; 
}
// Devolve o tempo de espera
int getWaitingTime(CASHIER *cashier) { 
  return cashier->waitingTime; 
}
// Devolve uma estimativa de quando a caixa está pronta
int getCashierAvailable(CASHIER *cashier) { 
  return cashier->cashierAvailable; 
}
// Devolve a fila de clientes
QUEUE *getClientQueue(CASHIER *cashier) { 
  return cashier->clientQueue; 
}