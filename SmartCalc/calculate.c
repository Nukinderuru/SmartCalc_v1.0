#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smart_calc.h"

int calculate(stack_t **rpn_input, double x, long double *result) {
  input_status status = 0;
  int empty = 0;
  long double res = 0.0;
  stack_t *prev_operand = NULL;
  stack_t *operands = NULL;
  stack_t *i = (*rpn_input);
  for (; i != NULL; i = i->next) {  // Если в стеке число или x
    if (i->priority == 1) {
      if (i->type == 1) i->value = x;
      push(&operands, NUM, i->value, 1);
    } else {  // В противном случае это оператор или функция
      if (operands) {
        switch (i->type) {
          case PLUS:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              res = prev_operand->value + operands->value;
              stack_t *temp = pop(&operands, &empty);
              operands->value = res;
              delete_list(&temp);
            }
            break;
          case MINUS:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              res = prev_operand->value - operands->value;
              stack_t *temp = pop(&operands, &empty);
              operands->value = res;
              delete_list(&temp);
            }
            break;
          case MULT:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              res = prev_operand->value * operands->value;
              stack_t *temp = pop(&operands, &empty);
              operands->value = res;
              delete_list(&temp);
            }
            break;
          case DIV:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              if (operands->value != 0.0) {
                res = prev_operand->value / operands->value;
                stack_t *temp = pop(&operands, &empty);
                operands->value = res;
                delete_list(&temp);
              } else {
                status = WRONG_EXPRESSION;
              }
            }
            break;
          case MOD:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              res = fmodl(prev_operand->value, operands->value);
              stack_t *temp = pop(&operands, &empty);
              operands->value = res;
              delete_list(&temp);
            }
            break;
          case EXP:
            if (operands->next == NULL)
              status = WRONG_EXPRESSION;
            else {
              prev_operand = operands->next;
              res = powl(prev_operand->value, operands->value);
              stack_t *temp = pop(&operands, &empty);
              operands->value = res;
              delete_list(&temp);
            }
            break;
          case COS:
            res = cosl(operands->value);
            operands->value = res;
            break;
          case SIN:
            res = sinl(operands->value);
            operands->value = res;
            break;
          case TAN:
            res = tanl(operands->value);
            operands->value = res;
            break;
          case ACOS:
            res = acosl(operands->value);
            operands->value = res;
            break;
          case ASIN:
            res = asinl(operands->value);
            operands->value = res;
            break;
          case ATAN:
            res = atanl(operands->value);
            operands->value = res;
            break;
          case SQRT:
            res = sqrtl(operands->value);
            operands->value = res;
            break;
          case LN:
            res = logl(operands->value);
            operands->value = res;
            break;
          case LOG:
            res = log10l(operands->value);
            operands->value = res;
            break;

          default:
            break;
        }
      } else {
        status = WRONG_EXPRESSION;
      }
    }
  }
  delete_list(&operands);
  *result = res;
  return status;
}
