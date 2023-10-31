#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/smart_calc.h"
#include "tests.h"

int compare_doubles(double a, double b) {
  double eps = 0.0000001;
  int status = (fabs(a - b) < eps) ? 0 : 1;
  return status;
}

int main() {
  int no_failed = 0;

  Suite *suites[] = {check_input_suite(), parce_input_suite(), make_rpn_suite(),
                     calculate_suite(), NULL};
  for (Suite **pS = suites; *pS != NULL; pS++) {
    SRunner *sr = srunner_create(*pS);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}