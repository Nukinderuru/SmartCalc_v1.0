#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/smart_calc.h"
#include "tests.h"

START_TEST(test_1) {
  char input[25] = "18+11*24/2^2";

  stack_t *result = NULL;
  push(&result, NUM, 18.0, 1);
  push(&result, PLUS, 0, 2);
  push(&result, NUM, 11.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 24.0, 1);
  push(&result, DIV, 0, 3);
  push(&result, NUM, 2.0, 1);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 2.0, 1);

  stack_t *parced_input = parce_input(input);
  stack_t *reversed = NULL;
  reverse_stack(&parced_input, &reversed);

  stack_t *i = (reversed);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&result);
  delete_list(&parced_input);
  delete_list(&reversed);
}
END_TEST

START_TEST(test_2) {
  char input[25] = "(123mod12)*(-2)-3";

  stack_t *result = NULL;
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 123.0, 1);
  push(&result, MOD, 0, 3);
  push(&result, NUM, 12.0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, MULT, 0, 3);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 0.0, 1);
  push(&result, MINUS, 0, 2);
  push(&result, NUM, 2.0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, MINUS, 0, 2);
  push(&result, NUM, 3.0, 1);

  stack_t *parced_input = parce_input(input);
  stack_t *reversed = NULL;
  reverse_stack(&parced_input, &reversed);

  stack_t *i = (reversed);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&result);
  delete_list(&parced_input);
  delete_list(&reversed);
}
END_TEST

START_TEST(test_3) {
  char input[25] = "-sin(2x)/(-cos(x))";

  stack_t *result = NULL;
  push(&result, NUM, 0.0, 1);
  push(&result, MINUS, 0, 2);
  push(&result, SIN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 2.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, DIV, 0, 3);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 0.0, 1);
  push(&result, MINUS, 0.0, 2);
  push(&result, COS, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, CL_B, 0, -1);

  stack_t *parced_input = parce_input(input);
  stack_t *reversed = NULL;
  reverse_stack(&parced_input, &reversed);

  stack_t *i = (reversed);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&result);
  delete_list(&parced_input);
  delete_list(&reversed);
}
END_TEST

START_TEST(test_4) {
  char input[100] =
      "(sqrt(144)*8mod3)+ln(3x)/log(25x)-(atan(3x)^3*tan(x)/(asin(x)-acos(x)))";

  stack_t *result = NULL;
  push(&result, OP_B, 0, -1);
  push(&result, SQRT, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 144.0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 8.0, 1);
  push(&result, MOD, 0, 3);
  push(&result, NUM, 3.0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, PLUS, 0, 2);
  push(&result, LN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 3.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, DIV, 0, 3);
  push(&result, LOG, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 25.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, MINUS, 0, 2);
  push(&result, OP_B, 0, -1);
  push(&result, ATAN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 3.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 3.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, TAN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, DIV, 0, 3);
  push(&result, OP_B, 0, -1);
  push(&result, ASIN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, MINUS, 0, 2);
  push(&result, ACOS, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, X, 0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, CL_B, 0, -1);
  push(&result, CL_B, 0, -1);

  stack_t *parced_input = parce_input(input);
  stack_t *reversed = NULL;
  reverse_stack(&parced_input, &reversed);

  stack_t *i = (reversed);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&result);
  delete_list(&parced_input);
  delete_list(&reversed);
}
END_TEST

START_TEST(test_5) {
  char input[100] = "123456.987+121*x-sin(3)/sqrt(144)";

  stack_t *result = NULL;
  push(&result, NUM, 123456.987, 1);
  push(&result, PLUS, 0, 2);
  push(&result, NUM, 121.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, MINUS, 0, 2);
  push(&result, SIN, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 3.0, 1);
  push(&result, CL_B, 0, -1);
  push(&result, DIV, 0, 3);
  push(&result, SQRT, 0, 5);
  push(&result, OP_B, 0, -1);
  push(&result, NUM, 144.0, 1);
  push(&result, CL_B, 0, -1);

  stack_t *parced_input = parce_input(input);
  stack_t *reversed = NULL;
  reverse_stack(&parced_input, &reversed);

  stack_t *i = (reversed);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&result);
  delete_list(&parced_input);
  delete_list(&reversed);
}
END_TEST

Suite *parce_input_suite(void) {
  Suite *s;
  TCase *tc_parce;

  s = suite_create("Parce input");

  tc_parce = tcase_create("Parce input");

  tcase_add_test(tc_parce, test_1);
  tcase_add_test(tc_parce, test_2);
  tcase_add_test(tc_parce, test_3);
  tcase_add_test(tc_parce, test_4);
  tcase_add_test(tc_parce, test_5);

  suite_add_tcase(s, tc_parce);

  return s;
}
