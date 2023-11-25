#include<stdio.h>
#include<locale.h>
#include "doubly-linked-lists/dll.h"
#include "singly-circled-linked-lists/scll.h"
#include "utils/utils.h"

typedef struct Node_Route {
  int code;
  struct Node_Stop* stops;
  struct Node_Route* next, * prev;
} Route;

int main(void) {
  setlocale(0, "");
  int option = 1, invalid = 0;
start:
  invalid = 0;
  do {
    clearConsole();
    printf("========== VARIANTE A ==========\n");
    if (invalid)
      printf("Opção Inválida\n"), printf("================================\n");
    printf("1- Desafio I\n");
    printf("2- Desafio II\n");
    printf("3- Sair\n");
    printf("[1-3]: ");
  } while ((invalid = (!scanf("%d", &option) || (option < 1 || option > 3))));

  int option2, last = 5, result;
  do {
    clearConsole();
    if (invalid) printf("Opção Inválida!\n");
    SCLL* head = scll_init();
    Route* routes = init_routes();
    switch (option) {
    case 1:
    challenge1:
      printf("========== DESAFIO I ==========\n");
      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Procurar\n");
      printf("4 - Imprimir\n");
      printf("5 - Dividir lista\n");
      printf("6 - Eliminar lista\n");
      printf("%d - Voltar\n", (last = 7));
      printf("[1-%d]: ", last);
      scanf("%d", &option2);
      if (option2 == last) {
        head = scll_clear(head);
        goto start;
      }
      invalid = option2 < 1 || option2 > last;
      switch (option2) {
      case 1:
        c1_insert(&head);
        goto challenge1;
        break;
      case 2:
        c1_remove(&head);
        goto challenge1;
        break;
      case 3:
        c1_find(&head);
        goto challenge1;
        break;
      case 4:
        clearConsole();
        scll_print(head);
        goto challenge1;
        break;
      case 5:
        clearConsole();
        c1_split(&head);
        goto challenge1;
        break;
      case 6:
        clearConsole();
        head = scll_clear(head);
        goto challenge1;
        break;
      }
      break;
    case 2:
    challenge2:
      last = 7;
      printf("========== DESAFIO II ==========\n");
      printf("1 - Inserir Rota\n");
      printf("2 - Remover Rota\n");
      printf("3 - Adicionar Paragem\n");
      printf("4 - Remover Paragem\n");
      printf("5 - Imprimir Rotas\n");
      printf("6 - Eliminar lista de rotas\n");
      if (routes) printf("7 - Maximo de passageiros na paragem de uma rota\n"), last++;
      printf("%d - Voltar\n[1-%d]: ", last, last);
      scanf("%d", &option2);
      if (option2 == last) {
        routes = clear_routes(routes);
        goto start;
      }
      invalid = option2 < 1 || option2 > last;
      switch (option2) {
      case 1:
        clearConsole();
        c2_insert(&routes);
        goto challenge2;
        break;
      case 2:
        clearConsole();
        c2_remove(&routes);
        goto challenge2;
        break;
      case 3:
        clearConsole();
        c2_add_stop(&routes);
        goto challenge2;
        break;

      case 4:
        clearConsole();
        c2_rm_stop(&routes);
        goto challenge2;
        break;
      case 5:
        clearConsole();
        c2_print(&routes);
        goto challenge2;
        break;
      case 6:
        clearConsole();
        routes = clear_routes(routes);
        goto challenge2;
        break;
      case 7:
        clearConsole();
        c2_max(&routes);
        goto challenge2;
        break;
      }
      break;
    case 3:
      printf("Muito Obrigado! ;)\n");
      printf("By:\n%s%s%s",
        "- Kélsio Mateus 20221473\n",
        "- Lukeny Silva 20220718\n",
        "- Matateu André 20212549\n"
      );
      goto end;
      break;
    default:
      invalid = 1;
    }
  } while (invalid);
end:
  return 0;
}