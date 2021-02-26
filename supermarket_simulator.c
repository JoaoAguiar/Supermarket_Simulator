#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./supermarket_simulator.h"

int main() {
  int clientsAffluence;
  int clientsAppetite;
  int numberCashiers;
  int numberCycles;

  printf("########## SUPERMARKET SIMULATOR ##########");
  printf("\n");
  printf("\n");
  printf("Affluence: ");
  scanf("%d", &clientsAffluence);
  printf("Appetite: ");
  scanf("%d", &clientsAppetite);
  printf("Number of Cashiers: ");
  scanf("%d", &numberCashiers);
  printf("Number of Cycles: ");
  scanf("%d", &numberCycles);

  simulator(clientsAffluence, clientsAppetite, numberCashiers, numberCycles);

  return 0;
}

// Simulador do supermercado
void simulator(int clientsAffluence, int clientsAppetite, int numberCashiers, int numberCycles) {
  CASHIER *cashiers[numberCashiers];
  int cycle;

  // Inicializa o gerador de numeros random
  srand(time(0));

  for(cycle=1; cycle<numberCashiers+1; cycle++) { 
    cashiers[cycle] = initCashier(cycle); 
  }
  for(cycle=1; cycle<numberCycles+1; cycle++) {
    printf("\n== Cycle %d ==\n", cycle);

    updateCashierClients(cycle, cashiers, numberCashiers); 

    int random = rand()%100;

    if(random <= clientsAffluence) {
      int numberProducts = rand()%(3*clientsAppetite) + 1;
      CLIENT *newClient = initClient(numberProducts, cycle);

      printf("--> Client created with %d products \n", numberProducts);

      int cashierChosen = rand()%numberCashiers + 1;
      enqueue(newClient, getClientQueue(cashiers[cashierChosen]));
    }

    showCashier(cashiers, numberCashiers);
  }

  printf("\n== END OF CASHIERS ==\n");

  //cycle = 1;

  while(cashierFull(cashiers, numberCashiers) == TRUE) {
    printf("\n== Cycle %d ==\n", cycle);

    updateCashierClients(cycle, cashiers, numberCashiers);
    showCashier(cashiers, numberCashiers);

    cycle++;
  }

  processesResults(cashiers, numberCashiers);

  return;
}

// Percorre as todas as caixas, actualizando as respectivas listas de clientes
void updateCashierClients(int cycle, CASHIER *cashiers[], int numberCashiers) {
  int i;

  for(i=1; i<numberCashiers+1; i++) {
    if(emptyCashier(cashiers[i])) { 
      setCashierAvailable(cashiers[i], cycle); 
    }
    else { 
      treatFirstClient(cycle, cashiers[i]); 
    }
  }

  return;
}

// Verifica se o primeiro cliente da caixa está despachado e actualiza a informacao da caixa
void treatFirstClient(int cycle, CASHIER* cashier) {
  CLIENT *client = peek(cashier->clientQueue);
  int activeTime = cycle - getCashierAvailable(cashier);
  int processedProducts = activeTime * getProductsProcessedPerUnitTime(cashier); 

  if(processedProducts >= (client->numberItems)) {
    setCashierAvailable(cashier, cycle+1);
    setNumberServedClients(cashier);
    setNumberProcessedProducts(cashier, client->numberItems);
    setWaitingTime(cashier, cycle - client->entryTime);
    removeClient(cashier);

    printf("--> Client served in the cashier %d \n", getCashierNumber(cashier));
  }

  return;
}

// Mostra para o ecra a representação externa de cada uma das caixas
void showCashier(CASHIER *cashiers[], int numberCashiers) {
  int i;

  for(i=1; i<numberCashiers+1; i++) { 
    printCashier(cashiers[i]); 
  }

  return;
}

// Verifica se alguma caixa tem clientes
BOOL1 fullCashier(CASHIER *cashiers[], int numberCashiers) {
  int i;

  for(i=1; i<numberCashiers+1; i++) {
    if(empty(cashiers[i]) == FALSE) { 
      return TRUE; 
    }
  }

  return FALSE;
}

// Estatisticas de cada caixa
void processesResults(CASHIER *cashiers[], int numberCashiers) {
  int i;

  printf("\n");

  for(i=1; i<numberCashiers+1; i++) {
    printf("Cashier %d (%d products by cycle) \n", cashiers[i]->numberCashier, cashiers[i]->productsProcessedPerUnitTime);

    if(cashiers[i]->numberServedClients != 0) {
      float averageProducts = ((float)cashiers[i]->numberProcessedProducts)/((float)cashiers[i]->numberServedClients);

      printf("%d clients served, media %.1f products/clients \n\n", cashiers[i]->numberServedClients, averageProducts);
    }
    else { 
      printf("%d clients served \n", cashiers[i]->numberServedClients); 
    }
  }

  return;
}
