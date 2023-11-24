#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

void clearConsole() {
  fflush(stdin);
#ifdef _WIN32
  system("cls");
#elif __linux__ || __APPLE__
  system("clear");
#else
  printf("Ambiente não suportado!");
#endif
}

