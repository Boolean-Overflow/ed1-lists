#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dll.h"

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

Route* init_routes() {
  return NULL;
}

Stop* init_stops() {
  return NULL;
}

Route* check_route(Route* route, int code) {
  if (!route) return route;
  Route* aux = route;
  while (aux->next && aux->code != code) aux = aux->next;

  if (aux->code == code) return aux;

  return NULL;
}

Stop* check_stop(Route* route, char* name) {
  Stop* aux = route->stops;
  while (aux->next && strcmp(aux->name, name)) aux = aux->next;
  if (!strcmp(aux->name, name)) return aux;
  return NULL;
}

Route* route_insert(Route* routes, Stop* stops) {
  Route* route = malloc(sizeof(Route));
  if (!route) {
    printf("Erro de Alocação\n");
    return routes;
  }

  route->stops = stops;
  route->next = route->prev = NULL;
  if (!routes) {
    route->code = 1;
    return route;
  }

  route->code = routes->code + 1;
  routes->prev = route;
  route->next = routes;
  routes = route;

  return routes;
}

Route* remove_route(Route* routes, int code) {
  Route* route = check_route(routes, code);
  if (!route) {
    printf("Rota não encontrada!\n");
    return routes;
  }
  Stop* p = route->stops;
  while (p) {
    Stop* p2 = p;
    free(p2);
    p = p->next;
  }

  if (route->prev) route->prev->next = route->next;

  if (route->next) {
    if (!route->prev) routes = route->next;
    route->next->prev = route->prev;
  }

  free(route);
  return routes;
}

Stop* add_stop(Stop* stops, char* name, int qtd) {
  Stop* stop = malloc(sizeof(Stop));
  if (!stop) {
    printf("Erro de Alocação\n");
    return NULL;
  }
  stop->name = malloc(20);
  strcpy(stop->name, name);

  stop->passengers = qtd;
  stop->next = stop->prev = NULL;

  if (!stops) return stop;

  stop->next = stops;
  stops->prev = stop;

  return stop;
}

Stop* remove_stop(Route* route, char* name) {
  Stop* stop = check_stop(route, name);
  if (!stop) {
    printf("Paragem nao encontrada.\n");
    return route->stops;
  }

  if (stop->prev) stop->prev->next = stop->next;
  if (stop->next) {
    if (!stop->prev) route->stops = stop->next;
    stop->next->prev = stop->prev;
  }
  free(stop->name);
  free(stop);
  return route->stops;
}

void print_route(Route* routes, int code) {
  Route* route = check_route(routes, code);
  if (!route) {
    printf("Rota nao encontrada.\n");
    return;
  }

  printf("Rota %d: \n", route->code);
  Stop* stops = route->stops;
  while (stops) {
    printf(" [ %d ] %s", stops->passengers, stops->name);
    stops = stops->next;
  }
}

Stop* best_stop(Route* routes, int code) {
  Route* route = check_route(routes, code);
  if (!route) return NULL;


  int m = 0;
  Stop* stops = route->stops, * stop = NULL;
  while (stops) {
    if (stops->passengers > m) stop = stops, m = stop->passengers;
    stops = stops->next;
  }

  return stop;
}

Route* clear_routes(Route* routes) {
  if (!routes) printf("Lista Vazia\n");
  else {
    while (routes) {
      Route* aux = routes;
      routes = routes->next;
      remove_route(aux, aux->code);
    }
  }

  return routes;
}