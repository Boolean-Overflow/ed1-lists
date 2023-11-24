#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include "scll.h"
struct Node {
  char value;
  struct Node* next;
};

SCLL* scll_init() {
  return NULL;
}

SCLL* add_node(SCLL* head, SCLL* node, int first) {
  if (!head) return (node->next = node);
  SCLL* t = head;
  while (t->next != head) t = t->next;
  node->next = head;
  t->next = node;

  return first ? head : node;
}

SCLL* scll_insert(SCLL* head, char value) {
  SCLL* node = (SCLL*)malloc(sizeof(SCLL));
  if (!node) {
    printf("\nAlocation Error\n");
    return head;
  }

  node->value = value;

  return add_node(head, node, 1);
}

void scll_print(SCLL* head) {
  SCLL* p = head;
  if (head) {
    do {
      printf(" %c ", p->value);
      p = p->next;
    } while (p != head);
    printf("\n");
  }
  else printf("Lista vazia\n");
}

int scll_find(SCLL* head, char c) {
  SCLL* q = head;
  int count = 0;
  if (!head) return -1;
  do {
    count++;
    if (q->value == c) return count;
    q = q->next;
  } while (q->next != head);
  return -1;
}

SCLL* scll_remove(SCLL* head, char c) {
  SCLL* prev = head, * act = head;
  if (!head)return NULL;
  if (head->next == head && head->value == c) head = NULL;
  else if (head->next == head && head->value != c) return head;
  else if (head->value == c) {
    while (act->next != head)act = act->next;
    head = prev->next;
    act->next = head;
    free(prev);
  }
  else
  {
    while (act->next != head && act->value != c) {
      prev = act;
      act = act->next;
    }
    if (act->value == c && act->next == head) {
      prev->next = head;
      free(act);//encontrou no fim
    }
    else if (act->value == c && act->next != head) {
      prev->next = act->next;
      free(act); //encontrou no meio
    }
  }
  return head;
}

int isVowel(char character) {
  char c = toupper(character);
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
int scll_split(SCLL** head, SCLL** v, SCLL** c) {
  if (!*head) return 0;
  SCLL* t = *head, * vowels = NULL, * consonants = NULL;
  SCLL* temp = NULL, * next = NULL;

  do {
    next = t->next;
    if (isVowel(t->value)) {
      temp = add_node(*v, t, 0);
      if (!vowels) *v = temp;
      vowels = temp;
    }
    else {
      temp = add_node(*c, t, 0);
      if (!consonants) *c = temp;
      consonants = temp;
    }
    t = next;
  } while (t != *head);

  if (vowels) vowels->next = *v;
  if (consonants) consonants->next = *c;

  vowels = consonants = *head = temp = NULL;

  return 1;
}

SCLL* scll_clear(SCLL* head) {
  if (!head) return NULL;

  SCLL* t = head;
  do {
    SCLL* temp = t;
    t = t->next;
    free(temp);
  } while (t != head);

  return NULL;
}
