#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>

int compare_doubles(double a, double b);
Suite *check_input_suite(void);
Suite *calculate_suite(void);
Suite *parce_input_suite(void);
Suite *make_rpn_suite(void);

#endif  // S21_TESTS_H_