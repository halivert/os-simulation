#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum state { INIT, WAITING, PROCESSING, FINISHED } STATE;

typedef struct process {
  int id;
  STATE state;
  int programCounter;
  char *name;
} Process;

Process *createProcess(int id, char *name) {
  Process *process = malloc(sizeof(Process));
  process->id = id;
  process->state = INIT;
  process->programCounter = 0;
  process->name = strdup(name);
  return process;
}

void printMenu() {
  printf("\n");
  printf("1. Create a new process\n");
  printf("2. Print all processes\n");
  printf("0. Exit\n");
}

int main() {
  /* Process *CPU = NULL; */
  /* Process *processTable = (Process *)malloc(sizeof(Process) * 10); */

  int processId = 1;
  int option;
  char *buffer = (char *)malloc(sizeof(char) * 30);

  do {
    printMenu();
    scanf("%d", &option);
    while ((getchar()) != '\n');

    switch (option) {
    case 1:
      printf("Enter process name: ");
      scanf("%[^\n]s", buffer);
      Process *process = createProcess(processId++, buffer);

      printf("Process created: %s\n", process->name);
      break;
    }

  } while (option != 0);
}
