#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./client.h"

// Inicializa
CLIENT *initClient(int items, int time) {
	// Reserva um bloco de memoria com um numero especifico de bytes
  	CLIENT *client =  (CLIENT *) malloc(sizeof(CLIENT));

  	client->numberItems = items;
  	client->entryTime = time;

  	return client;
}

// Faz print do numero de itens e do tempo de entrado
void printClient(CLIENT *client) {
	printf(" [%d:%d]", client->numberItems, client->entryTime);

	return;
}

/***** Getters *****/
// Devolve o numero de itens
int getNumberItems(CLIENT *client) { 
	return client->numberItems; 
}
// Devolve o tempo de entrada 
int getEntryTime(CLIENT *client) { 
	return client->entryTime; 
}