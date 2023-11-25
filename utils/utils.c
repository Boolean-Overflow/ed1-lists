#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
#include "../doubly-linked-lists/dll.h"
#include "../singly-circled-linked-lists/scll.h"

struct Node {
  char value;
  struct Node* next;
};

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

void c1_insert(SCLL** head) {
  char c;
  do {
    clearConsole();
    // if (head && head->value == c) printf("Nó inserido!\n");
    printf("Informe uma letra\n");
    printf("[$ para terminar]: ");
    c = getchar();
    if (c != '$') *head = scll_insert(*head, c);
  } while (c != '$');
}

void c1_remove(SCLL** head) {
  clearConsole();
  printf("Informe uma letra: ");
  char c = getchar();
  if (scll_find(*head, c) != -1) {
    *head = scll_remove(*head, c);
    printf("Letra removida com sucesso.\n");
    return;
  }

  printf("Letra nao encontrada.\n");
}

void c1_find(SCLL** head) {
  clearConsole();
  printf("Informe uma letra: \n");
  char c = getchar();

  if (scll_find(*head, c) != -1) {
    printf("Esta letra encontra-se na posicao %i.\n", scll_find(*head, c));
    return;
  }

  printf("Letra nao encontrada.\n");
}

void c1_split(SCLL** head) {
  SCLL* vowels = NULL, * consonants = NULL;
  int result = scll_split(head, &vowels, &consonants);

  if (result) {
    printf("Vogais: "), scll_print(vowels);
    printf("Consoantes: "), scll_print(consonants);
    vowels = scll_clear(vowels);
    consonants = scll_clear(consonants);
    return;
  }

  printf("Lista sem elementos para dividir!\n");
}

struct Node_Stop {
  char* name;
  int passengers;
  struct Node_Stop* next, * prev;
};

struct Node_Route {
  int code;
  struct Node_Stop* stops;
  struct Node_Route* next, * prev;
};

void c2_insert(Route** routes) {
  clearConsole();
  char name[20];
  int qtd = 0, valid = 1;
  Stop* stops = init_stops();

  do {
    clearConsole();
    printf("Informe um nome para a paragem: ");
    fgets(name, 20, stdin);
    do {
      if (qtd < 0) printf("[INVÁLIDO]");
      printf("Informe o numero de passageiros da paragem:");
      scanf("%d", &qtd);
    } while (qtd < 0);

    stops = add_stop(stops, name, qtd);

    printf("Continuar a adicionar?\n[1/0]:");
    while (!scanf("%d", &valid))
      printf("Valor Inválido!\n[1/0]:"), fflush(stdin);
  } while (valid == 1);

  *routes = route_insert(*routes, stops);
}

void c2_remove(Route** routes) {
  int code;
  clearConsole();
  printf("Informe o codigo da rota: \n");
  scanf("%d", &code);
  *routes = remove_route(*routes, code);
}

void c2_add_stop(Route** routes) {
  char name[20];
  int qtd, code, valid = 1;
  printf("Informe o codigo da rota: \n");
  scanf("%d", &code);
  fflush(stdin);

  Route* route = check_route(*routes, code);

  if (!route) {
    printf("Rota Inexistente!\n");
    return;
  }


  do {
    clearConsole();
    printf("Informe um nome para a paragem: ");
    fgets(name, 20, stdin);
    do {
      if (qtd < 0) printf("[INVÁLIDO]");
      printf("Informe o numero de passageiros da paragem:");
      scanf("%d", &qtd);
    } while (qtd < 0);
    route->stops = add_stop(route->stops, name, qtd);
    printf("Continuar a adicionar?\n[1/0]:");
    while (!scanf("%d", &valid)) printf("Valor Inválido!\n[1/0]:"), fflush(stdin);
  } while (valid == 1);

}

void c2_rm_stop(Route** routes) {
  char name[20];
  int code;
  printf("Informe o codigo da rota: \n");
  scanf("%d", &code);

  Route* route = check_route(*routes, code);

  if (!route) {
    printf("Rota Inexistente!\n");
    return;
  }
  fflush(stdin);
  printf("Informe um nome para a paragem:\n");
  fgets(name, 20, stdin);

  route->stops = remove_stop(route, name);
}

void c2_print(Route** routes) {
  int code;
  printf("Insira o codigo da rota:");
  scanf("%d", &code);

  print_route(*routes, code);
}

void c2_max(Route** routes) {
  int code;
  printf("Insira o codigo da rota:");
  scanf("%d", &code);

  Stop* stop = best_stop(*routes, code);
  if (!stop) printf("Rota Inválida!\n");
  else printf("%s é a paragem com mais passageiros com %d\n", stop->name, stop->passengers);
}