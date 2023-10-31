#include <math.h>
#include <stdio.h>
#include <string.h>

#include "smart_calc.h"

int check_input(const char *input) {
  input_status status = OK;
  int op_braces = 0, cl_braces = 0;
  for (int i = 0; i < (int)strlen(input); i++) {
    if (input[i] == '(') op_braces++;
    if (input[i] == ')') {
      cl_braces++;
      if (input[i - 1] == '(') status = WRONG_EXPRESSION;
    }
    if (status || (status = check_char(input, &i, &op_braces))) break;
  }
  if (op_braces != cl_braces) {
    status = WRONG_EXPRESSION;
  }
  return status;
}

int check_char(const char *input, int *i, int *op_braces) {
  input_status status = OK;
  int ind = *i;
  char beginnings[] = "aclmstx(", endings[] = "dx)";
  char nums[] = "0123456789", funcs[] = "aclst", operators[] = "-+*/^";
  char *op1 = strchr(operators, input[ind]);
  char *op2 = strchr(operators, input[ind + 1]);
  if (op1 && op2) {  // Два оператора подряд
    status = WRONG_EXPRESSION;
  }
  if (input[ind] == '(' && input[ind + 1] == ')') {
    status = WRONG_EXPRESSION;
  }
  if ((input[ind] == '-' || input[ind] == '+') &&
      (!strchr(beginnings, input[ind + 1])) &&
      (!strchr(nums, input[ind + 1])) && (!strchr(nums, input[ind - 1])) &&
      (!strchr(endings, input[ind - 1])) && (input[ind - 1] != '(') &&
      (ind != 0)) {
    status = WRONG_EXPRESSION;
  }
  if ((input[ind] == '/' || input[ind] == '*' || input[ind] == '^') &&
      ((!strchr(beginnings, input[ind + 1])) &&
       (!strchr(nums, input[ind + 1])) && (!strchr(endings, input[ind - 1])) &&
       (!strchr(nums, input[ind - 1])))) {
    status = WRONG_EXPRESSION;
  }
  if ((input[ind] == '.' || input[ind] == ',') &&
      ((!strchr(nums, input[ind + 1])) && (!strchr(nums, input[ind - 1])))) {
    status = WRONG_EXPRESSION;
  }
  if (input[ind] > 96 && input[ind] < 123) {
    if (strchr(funcs, input[ind]) &&
        ((ind == 0) || (strchr(operators, input[ind - 1])) ||
         (input[ind - 1] == 'd') || (input[ind - 1] == '('))) {
      status = check_function(input, &ind, op_braces);
    } else if (input[ind] == 'm' && (ind != 0)) {
      status = check_mod(input, &ind);
    }
  }
  *i = ind;
  return status;
}

int check_mod(const char *input, int *i) {
  int ind = *i, status = 0;
  if (input[ind + 1] == 'o' && input[ind + 2] == 'd') {
    ind += 2;
    if (input[ind + 1] < '0' || input[ind + 1] > '9') status = 2;
  } else
    status = 2;
  *i = ind;
  return status;
}

int check_acosAsinAtan(const char *input, int *i, int *op_braces) {
  int ind = *i, op = *op_braces, status = 0;
  if ((input[ind + 1] == 'c' && input[ind + 2] == 'o' &&
       input[ind + 3] == 's' && input[ind + 4] == '(') ||
      (input[ind + 1] == 's' && input[ind + 2] == 'i' &&
       input[ind + 3] == 'n' && input[ind + 4] == '(') ||
      (input[ind + 1] == 't' && input[ind + 2] == 'a' &&
       input[ind + 3] == 'n' && input[ind + 4] == '(')) {
    status = 0;
    ind += 4;
    op++;
  } else
    status = 2;
  *i = ind;
  *op_braces = op;
  return status;
}

int check_cos(const char *input, int *i, int *op_braces) {
  int ind = *i, op = *op_braces, status = 0;
  if (input[ind + 1] == 'o' && input[ind + 2] == 's' && input[ind + 3] == '(') {
    status = 0;
    ind += 3;
    op++;
  } else
    status = 2;
  *i = ind;
  *op_braces = op;
  return status;
}

int check_lnLog(const char *input, int *i, int *op_braces) {
  int ind = *i, op = *op_braces, status = 0;
  if (input[ind + 1] == 'n' && input[ind + 2] == '(') {
    status = 0;
    ind += 2;
    op++;
  } else if (input[ind + 1] == 'o' && input[ind + 2] == 'g' &&
             input[ind + 3] == '(') {
    status = 0;
    ind += 3;
    op++;
  } else
    status = 2;
  *i = ind;
  *op_braces = op;
  return status;
}

int check_sinSqrt(const char *input, int *i, int *op_braces) {
  int ind = *i, op = *op_braces, status = 0;
  if (input[ind + 1] == 'i' && input[ind + 2] == 'n' && input[ind + 3] == '(') {
    status = 0;
    ind += 3;
    op++;
  } else if (input[ind + 1] == 'q' && input[ind + 2] == 'r' &&
             input[ind + 3] == 't' && input[ind + 4] == '(') {
    status = 0;
    ind += 4;
    op++;
  } else {
    status = 2;
  }
  *i = ind;
  *op_braces = op;
  return status;
}

int check_tan(const char *input, int *i, int *op_braces) {
  int ind = *i, op = *op_braces, status = 0;
  if (input[ind + 1] == 'a' && input[ind + 2] == 'n' && input[ind + 3] == '(') {
    status = 0;
    ind += 3;
    op++;
  } else
    status = 2;
  *i = ind;
  *op_braces = op;
  return status;
}

int check_function(const char *input, int *i, int *op_braces) {
  int status = 0;
  char funcs[] = "aclst";
  switch (input[*i]) {
    case 'a':
      status = check_acosAsinAtan(input, i, op_braces);
      break;
    case 'c':
      status = check_cos(input, i, op_braces);
      break;
    case 'l':
      status = check_lnLog(input, i, op_braces);
      break;
    case 's':
      status = check_sinSqrt(input, i, op_braces);
      break;
    case 't':
      status = check_tan(input, i, op_braces);
      break;
  }
  if ((input[*i + 1] < '0' || input[*i + 1] > '9') &&
      (!strchr(funcs, input[*i + 1])) && (input[*i + 1] != 'x')) {
    status = 2;
  }
  return status;
}
