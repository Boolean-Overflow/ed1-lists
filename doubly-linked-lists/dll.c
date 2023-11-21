#include<stdio.h>
#include<stdlib.h>
#include "dll.h"

struct Node_Stop {
  char* name;
  int passagers;
  struct Node_Stop* next, * prev;
};

struct Node_Route {
  char* code;
  struct Node_Stop* stops;
  struct Node_Route* next, * prev;
};