#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/smart_calc.h"
#include "tests.h"

// Correct input
START_TEST(test_1) {
  char input[25] = "18+11*24/2^2";
  int status = check_input(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_2) {
  char input[25] = "(123mod12)*(-2)-3";
  int status = check_input(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_3) {
  char input[25] = "-sin(2x)/(-cos(x))";
  int status = check_input(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_4) {
  char input[100] =
      "(sqrt(144)*8mod3)+ln(3x)/log(25x)-(atan(3x)^3*tan(x)/(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_5) {
  char input[100] =
      "(sqrt(14.4)*8mod3,0)+ln(3x)/log(2.5x)-(atan(3x)^3*tan(x)/"
      "(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

// Inorrect input
START_TEST(test_wrong_1) {
  char input[25] = "18+11*+24/2^2";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_2) {
  char input[25] = "(123mod12*(-2)";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_3) {
  char input[25] = "-sin/(-cos(x))";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_4) {
  char input[100] =
      "(sqrt(144)*8mod3)+ln()/log(25x)-(atan(3x)^3*tan(x)/(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_5) {
  char input[100] =
      "(sqrt(14.4)*8mod3,0)+ln(3x)/lg(2.5x)-(atan(3x)^3*tan(x)/"
      "(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_6) {
  char input[100] =
      "(sqrt(*8)*8mod3,0)+ln(3x)/log(2.5x)-(atan(3x)^3*tan(x)/"
      "(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_7) {
  char input[100] =
      "(sqrt(8+1)*8mod3,0)+ln(sin(3x))/log(2.5x)-(atan(mod8)^3*tan(x)/"
      "(asin(x)-acos(x)))";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_8) {
  char input[100] = "(asin(x)-acos(x))mod+4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_9) {
  char input[100] = "(asin(y)-acos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_10) {
  char input[100] = "(asin(x-acos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_11) {
  char input[100] = "()asin(x-acos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_12) {
  char input[100] = "asin(x-acos(x))md4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_13) {
  char input[100] = "sins(x-acos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_14) {
  char input[100] = "sin(x-tann(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_15) {
  char input[100] = "asn(x-tan(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_16) {
  char input[100] = "asin(x-coss(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_17) {
  char input[100] = "asin(x.cos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_18) {
  char input[100] = "asin(x+cos(x))mod4/";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

START_TEST(test_wrong_19) {
  char input[100] = "asin(x(*cos(x))mod4";
  int status = check_input(input);
  ck_assert_int_eq(status, WRONG_EXPRESSION);
}
END_TEST

Suite *check_input_suite(void) {
  Suite *s;
  TCase *tc_check_correct, *tc_check_wrong;

  s = suite_create("Check input");

  tc_check_correct = tcase_create("Correct input");
  tc_check_wrong = tcase_create("Wrong input");

  // ---------- Correct input ----------
  tcase_add_test(tc_check_correct, test_1);
  tcase_add_test(tc_check_correct, test_2);
  tcase_add_test(tc_check_correct, test_3);
  tcase_add_test(tc_check_correct, test_4);
  tcase_add_test(tc_check_correct, test_5);
  // ---------- Incorrect input ----------
  tcase_add_test(tc_check_wrong, test_wrong_1);
  tcase_add_test(tc_check_wrong, test_wrong_2);
  tcase_add_test(tc_check_wrong, test_wrong_3);
  tcase_add_test(tc_check_wrong, test_wrong_4);
  tcase_add_test(tc_check_wrong, test_wrong_5);
  tcase_add_test(tc_check_wrong, test_wrong_6);
  tcase_add_test(tc_check_wrong, test_wrong_7);
  tcase_add_test(tc_check_wrong, test_wrong_8);
  tcase_add_test(tc_check_wrong, test_wrong_9);
  tcase_add_test(tc_check_wrong, test_wrong_10);
  tcase_add_test(tc_check_wrong, test_wrong_11);
  tcase_add_test(tc_check_wrong, test_wrong_12);
  tcase_add_test(tc_check_wrong, test_wrong_13);
  tcase_add_test(tc_check_wrong, test_wrong_14);
  tcase_add_test(tc_check_wrong, test_wrong_15);
  tcase_add_test(tc_check_wrong, test_wrong_16);
  tcase_add_test(tc_check_wrong, test_wrong_17);
  tcase_add_test(tc_check_wrong, test_wrong_18);
  tcase_add_test(tc_check_wrong, test_wrong_19);

  suite_add_tcase(s, tc_check_correct);
  suite_add_tcase(s, tc_check_wrong);

  return s;
}
