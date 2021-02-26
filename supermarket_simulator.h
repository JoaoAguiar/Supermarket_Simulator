#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./cashier.c"

typedef enum {FALSE1,TRUE1} BOOL1;

int main();
void simulator(int affluence, int appetite, int numberCashiers, int numberCycles);
void updateCashierClients(int cycle, CASHIER *cashiers[], int numberCashiers);
void treatFirstClient(int cycle, CASHIER *cashier);
void showCashier(CASHIER *cashiers[], int numberCashiers);
BOOL1 cashierFull(CASHIER *cashiers[], int numberCashiers);
void processesResults(CASHIER *cashiers[], int numberCashiers);