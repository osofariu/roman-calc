#include <check.h>
#include "roman_calculator.h"
#include "roman.h"

START_TEST (test_add_two_roman_numerals)
{
  char romanSum[MAX_MESSAGE_SIZE];
  char sumMessage[MAX_MESSAGE_SIZE];
  ck_assert_str_eq("II", add_roman_numerals("I","I", romanSum, sumMessage));
  ck_assert_str_eq("MCMLXXII", add_roman_numerals("MCMII", "LXX", romanSum, sumMessage));
}
END_TEST

START_TEST (test_validate_add_two_roman_numerals)
{
  // TODO: intercept stderr, and make sure the correct message gets written
  char romanSum[MAX_MESSAGE_SIZE];
  char sumMessage[MAX_MESSAGE_SIZE];
  ck_assert_str_eq("", add_roman_numerals("Z", "I", romanSum, sumMessage));
  ck_assert_str_eq("", romanSum);
  ck_assert_str_eq("Roman numeral contains invalid characters", sumMessage);

  ck_assert_str_eq("", add_roman_numerals("I", "Z", romanSum, sumMessage));
  ck_assert_str_eq("", romanSum);
  ck_assert_str_eq("Roman numeral contains invalid characters", sumMessage);

  ck_assert_str_eq("", add_roman_numerals("I", "MMMCMXCIX", romanSum, sumMessage));
  ck_assert_str_eq("", romanSum);
  ck_assert_str_eq("Roman numeral too large.", sumMessage);
}
END_TEST

START_TEST (test_subtract_two_roman_numerals)
{
  char subtractRomanResult[MAX_NUMERAL_SIZE];
  char subtractMessage[MAX_MESSAGE_SIZE];
  ck_assert_str_eq("IV", subtract_roman_numerals("V", "I", subtractRomanResult, subtractMessage));
  ck_assert_str_eq("", subtractMessage);
}
END_TEST

START_TEST (test_validate_subtract_two_roman_numerals)
{
  char romanSubtract[MAX_NUMERAL_SIZE];
  char subtractMessage[MAX_MESSAGE_SIZE];
  ck_assert_str_eq("", subtract_roman_numerals("I", "I", romanSubtract, subtractMessage));
  ck_assert_str_eq("Subtracting two roman numerals must result in a positive numeral", subtractMessage);
}
END_TEST

Suite *roman_calculator_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Roman Calculator");
  tc_core = tcase_create("add two roman numerals");

  tcase_add_test(tc_core, test_add_two_roman_numerals);
  tcase_add_test(tc_core, test_validate_add_two_roman_numerals);
  tcase_add_test(tc_core, test_subtract_two_roman_numerals);
  tcase_add_test(tc_core, test_validate_subtract_two_roman_numerals);
  suite_add_tcase(s, tc_core);

  return s;
}
