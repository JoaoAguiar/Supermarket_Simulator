#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./queue.c"

typedef enum {FALSE2,TRUE2} BOOL2;

typedef struct caixa {
 	int numberCashier;
  	int numberServedClients;
  	int numberProcessedProducts;
  	int productsProcessedPerUnitTime;
  	int waitingTime;
  	int cashierAvailable;
  	QUEUE *clientQueue;
} CASHIER;

CASHIER *initCashier(int numberCashier);
void removeClient(CASHIER *cashier);
BOOL2 emptyCashier(CASHIER *cashier);
void printCashier(CASHIER *cashier);
void setCashierAvailable(CASHIER *cashier, int value);
void setNumberClientsServed(CASHIER *cashier);
void setNumberProcessedProducts(CASHIER *cashier, int value);
void setWaitingTime(CASHIER *cashier, int value);
int getCashierNumber(CASHIER *cashier);
int getCashierAvailable(CASHIER *cashier);
int getNumberServedClients(CASHIER *cashier);
int getNumberProcessedProducts(CASHIER *cashier);
int getWaitingTime(CASHIER *cashier);
int getProductsProcessedPerUnitTime(CASHIER *cashier);
QUEUE *getClientQueue(CASHIER *cashier);