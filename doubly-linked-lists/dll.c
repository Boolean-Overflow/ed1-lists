#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dll.h"

typedef struct Node_Stop {
  char* name;
  int passagers;
  struct Node_Stop* next, * prev;
} Stop;

typedef struct Node_Route {
  char* code;
  struct Node_Stop* stops;
  struct Node_Route* next, * prev;
} Route;

Route* existe_rota(Route* route, char* c) {
  Route* aux = route;
  while (aux->next != NULL && (strcmp(aux->code, c) != 0)) {
    aux = aux->next;
  }
  if (strcmp(aux->code, c) == 0) return aux;
  return NULL;
}
Stop* existe_paragem(Route* route, char* c) {
  Stop* aux = route->stops;
  while (aux->next != NULL && (strcmp(aux->name, c) != 0)) {
    aux = aux->next;
  }
  if (strcmp(aux->name, c) == 0) return aux;;
  return NULL;
}

Route* inserir_rota(Route* route, char* c) {
  Route* nova_rota = malloc(sizeof(Route));
  nova_rota->code = c;
  nova_rota->stops = NULL;
  if (route == NULL) {
    nova_rota->next = NULL;
    nova_rota->prev = NULL;
    route = nova_rota;
  }
  else {
    route->prev = nova_rota;
    nova_rota->prev = NULL;
    nova_rota->next = route;
    route = nova_rota;
  }
  return route;
}
Route* eliminar_rota(Route* route, char* c) {
  Route* aux = existe_rota(route, c);
  if (aux != NULL) {
    Stop* p1 = aux->stops;
    Stop* p2;
    while (p1 != NULL) {
      p2 = p1;
      p1 = p1->next;
      free(p2->name);
      free(p2);
    }
    if (aux->prev == NULL) {
      aux->next->prev = NULL;
    }
    else if (aux->next == NULL) {
      aux->prev->next = NULL;
    }
    else {
      aux->next->prev = aux->prev;
      aux->prev->next = aux->next;
    }
    free(aux->code);
    free(aux);
  }
  else {
    printf("Rota nao encontrada\n");
  }
  return route;
}
int contar_rotas(Route* route) {
  if (!route) return 0;
  else return (1 + contar_rotas(route->next));
}

int contar_paragens(Stop* stop) {
  if (!stop) return 0;
  else return (1 + contar_paragens(stop->next));
}

Stop* inserir_paragem(Route* route, int qtd, char* name) {
  Stop* stop = malloc(sizeof(Stop));
  stop->name = name;
  stop->passagers = qtd;

  if (route->stops == NULL) {
    stop->next = stop->prev = NULL;
    route->stops = stop;
  }

  route->stops->prev = stop;
  stop->next = route->stops;
  stop->prev = NULL;

  return stop;
}

Stop* eliminar_paragem(Route* r, char* s) {
  Stop* aux = existe_paragem(r, s);
  if (aux != NULL) {
    if (aux->prev == NULL) {
      aux->next->prev = NULL;
    }
    else if (aux->next == NULL) {
      aux->prev->next = NULL;
    }
    else {
      aux->next->prev = aux->prev;
      aux->prev->next = aux->next;
    }
    free(aux);
  }
  else {
    printf("Paragem nao encontrada.\n");
  }
  return r->stops;
}

void imprimir_rota(Route* r, char* c) {
  Route* aux1 = existe_rota(r, c);
  if (aux1 != NULL) {
    printf("Rota %s: \n", aux1->code);
    Stop* aux2 = aux1->stops;
    while (aux2 != NULL) {
      printf("Paragem %s -> Passageiros: %i\n", aux2->name, aux2->passagers);
      aux2 = aux2->next;
    }
  }
  else {
    printf("Rota nao encontrada.\n");
  }
}

int numero_passageiros(Route* r, char* c) {
  if (existe_rota(r, c)) {
    int cont = 0;
    Stop* aux = r->stops;
    while (aux != NULL) {
      cont += aux->passagers;
      aux = aux->next;
    }
    return cont;
  }
  else {
    printf("Rota inexistente.\n");
    return 0;
  }
}