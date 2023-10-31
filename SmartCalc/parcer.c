#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smart_calc.h"

stack_t *parce_input(char *raw_input) {
  setlocale(LC_ALL, "en_US.UTF-8");
  stack_t *head = NULL;
  for (int i = 0; i < (int)strlen(raw_input); i++) {
    if (raw_input[i] >= '0' && raw_input[i] <= '9') {
      long double val = parce_number(raw_input, &i);
      push(&head, NUM, val, 1);
      if (raw_input[i] == 'x') {
        push(&head, MULT, 0, 3);
      }
    }
    if (raw_input[i] == 'x') push(&head, X, 0, 1);
    if (raw_input[i] == '+') push(&head, PLUS, 0, 2);
    if (raw_input[i] == '-') {
      if (head == NULL ||
          (raw_input[i - 1] < 0 && raw_input[i - 1] > 9 &&
           raw_input[i - 1] != ')') ||
          raw_input[i - 1] == '(') {
        // if (head == NULL || (head->type != 1 && head->type != 18)) {
        push(&head, NUM, 0.0, 1);
      }
      push(&head, MINUS, 0, 2);
    }
    if (raw_input[i] == '*') push(&head, MULT, 0, 3);
    if (raw_input[i] == '/') push(&head, DIV, 0, 3);
    if (raw_input[i] == 'm' && raw_input[i + 1] == 'o' &&
        raw_input[i + 2] == 'd')
      push(&head, MOD, 0, 3);
    if (raw_input[i] == '^') push(&head, EXP, 0, 4);
    if (raw_input[i] == 'c' && raw_input[i + 1] == 'o' &&
        raw_input[i + 2] == 's') {
      push(&head, COS, 0, 5);
      i += 2;
    }
    if (raw_input[i] == 's' && raw_input[i + 1] == 'i' &&
        raw_input[i + 2] == 'n') {
      push(&head, SIN, 0, 5);
      i += 2;
    }
    if (raw_input[i] == 't' && raw_input[i + 1] == 'a' &&
        raw_input[i + 2] == 'n') {
      push(&head, TAN, 0, 5);
      i += 2;
    }
    if (raw_input[i] == 'a' && raw_input[i + 1] == 'c' &&
        raw_input[i + 2] == 'o' && raw_input[i + 3] == 's') {
      push(&head, ACOS, 0, 5);
      i += 3;
    }
    if (raw_input[i] == 'a' && raw_input[i + 1] == 's' &&
        raw_input[i + 2] == 'i' && raw_input[i + 3] == 'n') {
      push(&head, ASIN, 0, 5);
      i += 3;
    }
    if (raw_input[i] == 'a' && raw_input[i + 1] == 't' &&
        raw_input[i + 2] == 'a' && raw_input[i + 3] == 'n') {
      push(&head, ATAN, 0, 5);
      i += 3;
    }
    if (raw_input[i] == 's' && raw_input[i + 1] == 'q' &&
        raw_input[i + 2] == 'r' && raw_input[i + 3] == 't') {
      push(&head, SQRT, 0, 5);
      i += 3;
    }
    if (raw_input[i] == 'l' && raw_input[i + 1] == 'n') {
      push(&head, LN, 0, 5);
      i++;
    }
    if (raw_input[i] == 'l' && raw_input[i + 1] == 'o' &&
        raw_input[i + 2] == 'g') {
      push(&head, LOG, 0, 5);
      i += 2;
    }
    if (raw_input[i] == '(') push(&head, OP_B, 0, -1);
    if (raw_input[i] == ')') push(&head, CL_B, 0, -1);
  }
  stack_t *reversed = NULL;
  reverse_stack(&head, &reversed);
  delete_list(&head);
  return reversed;
}

long double parce_number(char *input, int *i) {
  int ind = *i;
  int y = 0;
  char chislo[256] = "";
  while ((input[ind] >= '0' && input[ind] <= '9') || (input[ind] == '.')) {
    //    if (input[ind] == '.')
    //      chislo[y] = ',';
    //    else
    chislo[y] = input[ind];
    ind++;
    y++;
  }
  *i = ind;
  char *end = NULL;
  return strtold(chislo, &end);
}
