#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smart_calc.h"

void push(stack_t **head, int type, double value, int priority) {
  stack_t *tmp = (stack_t *)calloc(1, sizeof(stack_t));
  tmp->value = value;
  tmp->type = type;
  tmp->priority = priority;
  tmp->next = (*head);
  (*head) = tmp;
}

stack_t *pop(stack_t **head, int *empty) {
  stack_t *prev = NULL;
  stack_t *data = (stack_t *)calloc(1, sizeof(stack_t));
  if (head == NULL) {
    fprintf(stderr, "Stack is empty.\n");
    exit(1);
  }
  prev = (*head);
  data->value = prev->value;
  data->type = prev->type;
  data->priority = prev->priority;
  data->next = NULL;
  if ((*head)->next == NULL) *empty = 1;
  (*head) = (*head)->next;
  free(prev);
  return data;
}

void reverse_stack(stack_t **head, stack_t **new_head) {
  stack_t *i = (*head);
  for (; i != NULL; i = i->next) {
    push(new_head, i->type, i->value, i->priority);
  }
}

void delete_list(stack_t **head) {
  stack_t *prev = NULL;
  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }
  free(*head);
}

// void print_stack(stack_t **head) {
//   stack_t *i = (*head);
//   for (; i != NULL; i = i->next) {
//     printf("Value: %.7Lf, type: %d, priority: %d\n", i->value, i->type,
//            i->priority);
//   }
// }
