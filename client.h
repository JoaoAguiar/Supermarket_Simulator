#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cliente {
  int numberItems;
  int entryTime;
} CLIENT;

CLIENT *initClient(int items, int time);
void printClient(CLIENT *client);
int getNumberItems(CLIENT *client);
int getEntryTime(CLIENT *client);