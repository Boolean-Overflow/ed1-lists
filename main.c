#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include "doubly-linked-lists/dll.h"
#include "singly-circled-linked-lists/scll.h"
#include "utils/utils.h"

typedef struct Node {
  char value;
  struct Node* next;
} Node;


int main(void) {
  setlocale(0, "");
  int option = 1, invalid = 0;
start:
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
    SCLL* vowels = NULL, * consonants = NULL;
    char c;
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
      scanf("%d", &option2);
      if (option2 == last) goto start;
      invalid = option2 < 1 || option2 > last;
      switch (option2) {
      case 1:
        do {
          clearConsole();
          if (head && head->value == c) printf("Nó inserido!\n");
          printf("Informe uma letra\n");
          printf("[$ para terminar]:");
          c = getchar();
          if (c != '$') head = scll_insert(head, c);
        } while (c != '$');
        goto challenge1;
        break;
      case 4:
        clearConsole();
        scll_print(head);
        goto challenge1;
        break;
      case 5:
        result = scll_split(&head, &vowels, &consonants);
        if (result) {
          printf("Vogais: "), scll_print(vowels);
          printf("Consoantes: "), scll_print(consonants);
          vowels = scll_clear(vowels);
          consonants = scll_clear(consonants);
        }
        else printf("Lista sem elementos para dividir!\n");
        goto challenge1;
        break;
      }

      break;
    case 2:
      printf("========== DESAFIO II ==========\n");
      printf("1 - Inserir Rota\n");
      printf("2 - Remover Rota\n");
      printf("3 - Imprimir Rotas\n");
      printf("4 - Eliminar lista de rotas\n");
      if (0) printf("5 - Encerrar\n"), last++;
      printf("%d - Voltar\n", last);
      scanf("%d", &option2);
      if (option2 == last) goto start;
      invalid = option2 < 1 || option2 > last;
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
  } while ((invalid));
end:
  return 0;
}