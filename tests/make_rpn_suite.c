#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/smart_calc.h"
#include "tests.h"

START_TEST(test_1) {
  // 18+11*24/2^2

  stack_t *infix = NULL;
  push(&infix, NUM, 18.0, 1);
  push(&infix, PLUS, 0, 2);
  push(&infix, NUM, 11.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, NUM, 24.0, 1);
  push(&infix, DIV, 0, 3);
  push(&infix, NUM, 2.0, 1);
  push(&infix, EXP, 0, 4);
  push(&infix, NUM, 2.0, 1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, PLUS, 0, 2);
  push(&result, DIV, 0, 3);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 2.0, 1);
  push(&result, NUM, 2.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 24.0, 1);
  push(&result, NUM, 11.0, 1);
  push(&result, NUM, 18.0, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

START_TEST(test_2) {
  // (123mod12)*(-2)-3

  stack_t *infix = NULL;
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 123.0, 1);
  push(&infix, MOD, 0, 3);
  push(&infix, NUM, 12.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MULT, 0, 3);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 0.0, 1);
  push(&infix, MINUS, 0, 2);
  push(&infix, NUM, 2.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MINUS, 0, 2);
  push(&infix, NUM, 3.0, 1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, MINUS, 0, 2);
  push(&result, NUM, 3.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, MINUS, 0, 2);
  push(&result, NUM, 2.0, 1);
  push(&result, NUM, 0, 1);
  push(&result, MOD, 0, 3);
  push(&result, NUM, 12.0, 1);
  push(&result, NUM, 123.0, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

START_TEST(test_3) {
  // -sin(2x)/(-cos(x))

  stack_t *infix = NULL;
  push(&infix, NUM, 0.0, 1);
  push(&infix, MINUS, 0, 2);
  push(&infix, SIN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 2.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, DIV, 0, 3);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 0.0, 1);
  push(&infix, MINUS, 0.0, 2);
  push(&infix, COS, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, CL_B, 0, -1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, MINUS, 0, 2);
  push(&result, DIV, 0, 3);
  push(&result, MINUS, 0, 2);
  push(&result, COS, 0, 5);
  push(&result, X, 0, 1);
  push(&result, NUM, 0, 1);
  push(&result, SIN, 0, 5);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, NUM, 2.0, 1);
  push(&result, NUM, 0, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

START_TEST(test_4) {
  //(sqrt(144)*8mod3)+ln(3x)/log(25x)-(atan(3x)^3*tan(x)/(asin(x)-acos(x)))

  stack_t *infix = NULL;
  push(&infix, OP_B, 0, -1);
  push(&infix, SQRT, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 144.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MULT, 0, 3);
  push(&infix, NUM, 8.0, 1);
  push(&infix, MOD, 0, 3);
  push(&infix, NUM, 3.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, PLUS, 0, 2);
  push(&infix, LN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 3.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, DIV, 0, 3);
  push(&infix, LOG, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 25.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MINUS, 0, 2);
  push(&infix, OP_B, 0, -1);
  push(&infix, ATAN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 3.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, EXP, 0, 4);
  push(&infix, NUM, 3.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, TAN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, DIV, 0, 3);
  push(&infix, OP_B, 0, -1);
  push(&infix, ASIN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MINUS, 0, 2);
  push(&infix, ACOS, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, X, 0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, CL_B, 0, -1);
  push(&infix, CL_B, 0, -1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, MINUS, 0, 2);
  push(&result, DIV, 0, 3);
  push(&result, MINUS, 0, 2);
  push(&result, ACOS, 0, 5);
  push(&result, X, 0, 1);
  push(&result, ASIN, 0, 5);
  push(&result, X, 0, 1);
  push(&result, MULT, 0, 3);
  push(&result, TAN, 0, 5);
  push(&result, X, 0, 1);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 3.0, 1);
  push(&result, ATAN, 0, 5);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, NUM, 3.0, 1);
  push(&result, PLUS, 0, 2);
  push(&result, DIV, 0, 3);
  push(&result, LOG, 0, 5);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, NUM, 25.0, 1);
  push(&result, LN, 0, 5);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, NUM, 3.0, 1);
  push(&result, MOD, 0, 3);
  push(&result, NUM, 3.0, 1);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 8.0, 1);
  push(&result, SQRT, 0, 5);
  push(&result, NUM, 144.0, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

START_TEST(test_5) {
  // 123456.987+121*x-sin(3)/sqrt(144)

  stack_t *infix = NULL;
  push(&infix, NUM, 123456.987, 1);
  push(&infix, PLUS, 0, 2);
  push(&infix, NUM, 121.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, X, 0, 1);
  push(&infix, MINUS, 0, 2);
  push(&infix, SIN, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 3.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, DIV, 0, 3);
  push(&infix, SQRT, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 144.0, 1);
  push(&infix, CL_B, 0, -1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, MINUS, 0, 2);
  push(&result, DIV, 0, 3);
  push(&result, SQRT, 0, 5);
  push(&result, NUM, 144.0, 1);
  push(&result, SIN, 0, 5);
  push(&result, NUM, 3.0, 1);
  push(&result, PLUS, 0, 2);
  push(&result, MULT, 0, 3);
  push(&result, X, 0, 1);
  push(&result, NUM, 121.0, 1);
  push(&result, NUM, 123456.987, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

START_TEST(test_6) {
  // sqrt((9^3-sqrt(81)-2^2*5)/7+3*7)+0.111

  stack_t *infix = NULL;
  push(&infix, SQRT, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 9.0, 1);
  push(&infix, EXP, 0, 4);
  push(&infix, NUM, 3.0, 1);
  push(&infix, MINUS, 0, 2);
  push(&infix, SQRT, 0, 5);
  push(&infix, OP_B, 0, -1);
  push(&infix, NUM, 81.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, MINUS, 0, 2);
  push(&infix, NUM, 2.0, 1);
  push(&infix, EXP, 0, 4);
  push(&infix, NUM, 2.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, NUM, 5.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, DIV, 0, 3);
  push(&infix, NUM, 7.0, 1);
  push(&infix, PLUS, 0, 2);
  push(&infix, NUM, 3.0, 1);
  push(&infix, MULT, 0, 3);
  push(&infix, NUM, 7.0, 1);
  push(&infix, CL_B, 0, -1);
  push(&infix, PLUS, 0, 2);
  push(&infix, NUM, 0.111, 1);
  stack_t *reversed = NULL;
  reverse_stack(&infix, &reversed);

  stack_t *rpn = make_reverse_polish_notation(&reversed);
  stack_t *result = NULL;
  push(&result, PLUS, 0, 2);
  push(&result, NUM, 0.111, 1);
  push(&result, SQRT, 0, 5);
  push(&result, PLUS, 0, 2);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 7.0, 1);
  push(&result, NUM, 3.0, 1);
  push(&result, DIV, 0, 3);
  push(&result, NUM, 7.0, 1);
  push(&result, MINUS, 0, 2);
  push(&result, MULT, 0, 3);
  push(&result, NUM, 5.0, 1);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 2.0, 1);
  push(&result, NUM, 2.0, 1);
  push(&result, MINUS, 0, 2);
  push(&result, SQRT, 0, 5);
  push(&result, NUM, 81.0, 1);
  push(&result, EXP, 0, 4);
  push(&result, NUM, 3.0, 1);
  push(&result, NUM, 9.0, 1);

  stack_t *i = (rpn);
  stack_t *y = (result);

  for (; i != NULL; i = i->next) {
    ck_assert_int_eq(i->type, y->type);
    ck_assert_int_eq(i->priority, y->priority);
    int equal = compare_doubles(i->value, y->value);
    ck_assert_int_eq(equal, OK);
    y = y->next;
  }

  delete_list(&infix);
  delete_list(&reversed);
  delete_list(&rpn);
  delete_list(&result);
}
END_TEST

Suite *make_rpn_suite(void) {
  Suite *s;
  TCase *tc_make_rpn;

  s = suite_create("Make RPN");

  tc_make_rpn = tcase_create("Make RPN");

  tcase_add_test(tc_make_rpn, test_1);
  tcase_add_test(tc_make_rpn, test_2);
  tcase_add_test(tc_make_rpn, test_3);
  tcase_add_test(tc_make_rpn, test_4);
  tcase_add_test(tc_make_rpn, test_5);
  tcase_add_test(tc_make_rpn, test_6);

  suite_add_tcase(s, tc_make_rpn);

  return s;
}
