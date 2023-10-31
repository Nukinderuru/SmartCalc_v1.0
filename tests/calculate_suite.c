#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/smart_calc.h"
#include "tests.h"

// Correct input
START_TEST(test_1) {
  // 18+11*24/2^2
  stack_t *input = NULL;
  push(&input, PLUS, 0, 2);
  push(&input, DIV, 0, 3);
  push(&input, EXP, 0, 4);
  push(&input, NUM, 2.0, 1);
  push(&input, NUM, 2.0, 1);
  push(&input, MULT, 0, 3);
  push(&input, NUM, 24.0, 1);
  push(&input, NUM, 11.0, 1);
  push(&input, NUM, 18.0, 1);

  long double result = 0.0;
  long double real_result = 84;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_2) {
  // (123mod12)*(-2)-3
  stack_t *input = NULL;
  push(&input, MINUS, 0, 2);
  push(&input, NUM, 3.0, 1);
  push(&input, MULT, 0, 3);
  push(&input, MINUS, 0, 2);
  push(&input, NUM, 2.0, 1);
  push(&input, NUM, 0, 1);
  push(&input, MOD, 0, 3);
  push(&input, NUM, 12.0, 1);
  push(&input, NUM, 123.0, 1);

  long double result = 0.0;
  long double real_result = -9;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_3) {
  // -sin(2x)/(-cos(x))
  stack_t *input = NULL;
  push(&input, MINUS, 0, 2);
  push(&input, DIV, 0, 3);
  push(&input, MINUS, 0, 2);
  push(&input, COS, 0, 5);
  push(&input, X, 0, 1);
  push(&input, NUM, 0, 1);
  push(&input, SIN, 0, 5);
  push(&input, MULT, 0, 3);
  push(&input, X, 0, 1);
  push(&input, NUM, 2.0, 1);
  push(&input, NUM, 0, 1);

  long double result = 0.0;
  long double real_result = 1.81859485365;
  int status = calculate(&input, 2.0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_4) {
  // sqrt(144)*(8mod3)
  stack_t *input = NULL;
  push(&input, MULT, 0, 3);
  push(&input, MOD, 0, 3);
  push(&input, NUM, 3.0, 1);
  push(&input, NUM, 8.0, 1);
  push(&input, SQRT, 0, 5);
  push(&input, NUM, 144.0, 1);

  long double result = 0.0;
  long double real_result = 24;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_5) {
  // ln(3x)/log(25x)
  stack_t *input = NULL;
  push(&input, DIV, 0, 3);
  push(&input, LOG, 0, 5);
  push(&input, MULT, 0, 3);
  push(&input, X, 0, 1);
  push(&input, NUM, 25.0, 1);
  push(&input, LN, 0, 5);
  push(&input, MULT, 0, 3);
  push(&input, X, 0, 1);
  push(&input, NUM, 3.0, 1);

  long double result = 0.0;
  long double real_result = 0.36964300014;
  int status = calculate(&input, 0.5, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_6) {
  // tan(3x)^3*tan(x)/(sin(x)-cos(x))
  stack_t *input = NULL;
  push(&input, MULT, 0, 3);
  push(&input, DIV, 0, 3);
  push(&input, MINUS, 0, 2);
  push(&input, COS, 0, 5);
  push(&input, X, 0, 1);
  push(&input, SIN, 0, 5);
  push(&input, X, 0, 1);
  push(&input, TAN, 0, 5);
  push(&input, X, 0, 1);
  push(&input, EXP, 0, 4);
  push(&input, NUM, 3.0, 1);
  push(&input, TAN, 0, 5);
  push(&input, MULT, 0, 3);
  push(&input, X, 0, 1);
  push(&input, NUM, 3.0, 1);

  long double result = 0.0;
  long double real_result = 2.88548821074;
  int status = calculate(&input, 4.0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_7) {
  // sqrt((9^3-sqrt(81)-2^2*5)/7+3*7)+0.111

  stack_t *input = NULL;
  push(&input, PLUS, 0, 2);
  push(&input, NUM, 0.111, 1);
  push(&input, SQRT, 0, 5);
  push(&input, PLUS, 0, 2);
  push(&input, MULT, 0, 3);
  push(&input, NUM, 7.0, 1);
  push(&input, NUM, 3.0, 1);
  push(&input, DIV, 0, 3);
  push(&input, NUM, 7.0, 1);
  push(&input, MINUS, 0, 2);
  push(&input, MULT, 0, 3);
  push(&input, NUM, 5.0, 1);
  push(&input, EXP, 0, 4);
  push(&input, NUM, 2.0, 1);
  push(&input, NUM, 2.0, 1);
  push(&input, MINUS, 0, 2);
  push(&input, SQRT, 0, 5);
  push(&input, NUM, 81.0, 1);
  push(&input, EXP, 0, 4);
  push(&input, NUM, 3.0, 1);
  push(&input, NUM, 9.0, 1);

  long double result = 0.0;
  long double real_result = 11.111;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_8) {
  // 18-8
  stack_t *input = NULL;
  push(&input, MINUS, 0, 2);
  push(&input, NUM, 8.0, 1);
  push(&input, NUM, 18.0, 1);

  long double result = 0.0;
  long double real_result = 10.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_9) {
  // 88/1.1
  stack_t *input = NULL;
  push(&input, DIV, 0, 3);
  push(&input, NUM, 1.1, 1);
  push(&input, NUM, 88.0, 1);

  long double result = 0.0;
  long double real_result = 80.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_10) {
  // 88/1.1
  stack_t *input = NULL;
  push(&input, MOD, 0, 3);
  push(&input, NUM, 5.0, 1);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  long double real_result = 2.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_11) {
  // 1.48765509 + 1.48765509
  stack_t *input = NULL;
  push(&input, PLUS, 0, 2);
  push(&input, ATAN, 0, 5);
  push(&input, NUM, 12.0, 1);
  push(&input, ATAN, 0, 5);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  long double real_result = 2.97531018;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

START_TEST(test_12) {
  stack_t *input = NULL;
  push(&input, PLUS, 0, 2);
  push(&input, ASIN, 0, 5);
  push(&input, COS, 0, 5);
  push(&input, NUM, 11.0, 1);
  push(&input, ACOS, 0, 5);
  push(&input, COS, 0, 5);
  push(&input, NUM, 11.0, 1);

  long double result = 0.0;
  long double real_result = acosl(cosl(11.0)) + asinl(cosl(11.0));
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, OK);

  int equal = compare_doubles((double)result, (double)real_result);
  ck_assert_int_eq(equal, OK);

  delete_list(&input);
}
END_TEST

// Wrong input
START_TEST(test_wrong_1) {
  stack_t *input = NULL;
  push(&input, MOD, 0, 3);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

START_TEST(test_wrong_2) {
  stack_t *input = NULL;
  push(&input, PLUS, 0, 2);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

START_TEST(test_wrong_3) {
  stack_t *input = NULL;
  push(&input, MINUS, 0, 2);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

START_TEST(test_wrong_4) {
  stack_t *input = NULL;
  push(&input, MULT, 0, 3);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

START_TEST(test_wrong_5) {
  stack_t *input = NULL;
  push(&input, DIV, 0, 3);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

START_TEST(test_wrong_6) {
  stack_t *input = NULL;
  push(&input, DIV, 0, 3);
  push(&input, NUM, 0.0, 1);
  push(&input, NUM, 12.0, 1);

  long double result = 0.0;
  int status = calculate(&input, 0, &result);
  ck_assert_int_eq(status, WRONG_EXPRESSION);

  delete_list(&input);
}
END_TEST

Suite *calculate_suite(void) {
  Suite *s;
  TCase *tc_calc, *tc_calc_wrong;

  s = suite_create("Calculate");

  tc_calc = tcase_create("Correct input");
  tc_calc_wrong = tcase_create("Wrong input");

  // ---------- Correct input ----------
  tcase_add_test(tc_calc, test_1);
  tcase_add_test(tc_calc, test_2);
  tcase_add_test(tc_calc, test_3);
  tcase_add_test(tc_calc, test_4);
  tcase_add_test(tc_calc, test_5);
  tcase_add_test(tc_calc, test_6);
  tcase_add_test(tc_calc, test_7);
  tcase_add_test(tc_calc, test_8);
  tcase_add_test(tc_calc, test_9);
  tcase_add_test(tc_calc, test_10);
  tcase_add_test(tc_calc, test_11);
  tcase_add_test(tc_calc, test_12);

  // ---------- Wrong input ------------
  tcase_add_test(tc_calc_wrong, test_wrong_1);
  tcase_add_test(tc_calc_wrong, test_wrong_2);
  tcase_add_test(tc_calc_wrong, test_wrong_3);
  tcase_add_test(tc_calc_wrong, test_wrong_4);
  tcase_add_test(tc_calc_wrong, test_wrong_5);
  tcase_add_test(tc_calc_wrong, test_wrong_6);

  suite_add_tcase(s, tc_calc);
  suite_add_tcase(s, tc_calc_wrong);

  return s;
}
