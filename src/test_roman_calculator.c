#include <check.h>
#include <stdlib.h>
#include "roman_calculator.h"

START_TEST (test_add_two_roman_numerals)
{
  char romanSum[50];
  ck_assert_str_eq("II", add_roman_numerals("I","I", romanSum));
  ck_assert_str_eq("MCMLXXII", add_roman_numerals("MCMII", "LXX", romanSum));
}
END_TEST

Suite *roman_calculator_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Roman Calculator");
  tc_core = tcase_create("add two roman numerals");

  tcase_add_test(tc_core, test_add_two_roman_numerals);
  suite_add_tcase(s, tc_core);

  return s;
}
