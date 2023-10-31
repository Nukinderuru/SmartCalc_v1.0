#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef enum { OK, INPUT_TOO_BIG, WRONG_EXPRESSION } input_status;

typedef enum {
  NUM,
  X,
  PLUS,
  MINUS,
  MULT,
  DIV,
  MOD,
  EXP,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  OP_B,
  CL_B
} type_t;

typedef struct stack_t {
  long double value;
  int priority;
  type_t type;
  struct stack_t *next;
} stack_t;

// Calculator
int check_input(const char *input);
int check_char(const char *input, int *i, int *op_braces);
int check_acosAsinAtan(const char *input, int *i, int *op_braces);
int check_cos(const char *input, int *i, int *op_braces);
int check_lnLog(const char *input, int *i, int *op_braces);
int check_mod(const char *input, int *i);
int check_sinSqrt(const char *input, int *i, int *op_braces);
int check_tan(const char *input, int *i, int *op_braces);
int check_function(const char *input, int *i, int *op_braces);
stack_t *parce_input(char *raw_input);
long double parce_number(char *input, int *i);
// int compare_doubles(double a, double b);
void deal_with_operator(stack_t **i, stack_t **support, stack_t **output);
stack_t *make_reverse_polish_notation(stack_t **input);
int calculate(stack_t **rpn_input, double x, long double *result);
void push(stack_t **head, int type, double value, int priority);
stack_t *pop(stack_t **head, int *empty);
stack_t *peek(stack_t **head);
void reverse_stack(stack_t **head, stack_t **new_head);
void delete_list(stack_t **head);
void print_stack(stack_t **head);

#endif  // CALCULATOR_H