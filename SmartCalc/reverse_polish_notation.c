#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smart_calc.h"

stack_t *make_reverse_polish_notation(stack_t **input) {
  stack_t *output = NULL;
  stack_t *support = NULL;
  stack_t *i = (*input);
  int empty = 0;
  for (; i != NULL; i = i->next) {
    if (i->priority == 1) {
      push(&output, i->type, i->value, i->priority);
    } else if (i->type == OP_B) {
      push(&support, i->type, i->value, i->priority);
    } else if (i->type == CL_B) {
      int op_br = 0;
      while (!op_br) {
        stack_t *temp = pop(&support, &empty);
        if (temp->type == OP_B)
          op_br = 1;
        else
          push(&output, temp->type, temp->value, temp->priority);
        delete_list(&temp);
      }
    } else if (i->priority > 1) {
      if (support == NULL || support->priority < i->priority) {
        push(&support, i->type, i->value, i->priority);
      } else {
        deal_with_operator(&i, &support, &output);
      }
    }
  }
  if (support != NULL) {
    for (stack_t *y = support; y != NULL;) {
      y = y->next;
      if (support) {
        stack_t *temp = pop(&support, &empty);
        push(&output, temp->type, temp->value, temp->priority);
        delete_list(&temp);
      }
    }
  }
  stack_t *reversed = NULL;
  reverse_stack(&output, &reversed);

  delete_list(&output);
  return reversed;
}

void deal_with_operator(stack_t **i, stack_t **support, stack_t **output) {
  int empty = 0;
  stack_t *temp = pop(support, &empty);
  push(output, temp->type, temp->value, temp->priority);
  if (empty || (*support)->priority < (*i)->priority) {
    push(support, (*i)->type, (*i)->value, (*i)->priority);
  } else {
    deal_with_operator(i, support, output);
  }
  delete_list(&temp);
}
