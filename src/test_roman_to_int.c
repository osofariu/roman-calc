#include <check.h>
#include <stdlib.h>
#include "roman_to_int.h"

START_TEST (test_roman_values)
{
  ck_assert_int_eq(1, roman_value("I"));
  ck_assert_int_eq(5, roman_value("V"));
  ck_assert_int_eq(10, roman_value("X"));
  ck_assert_int_eq(50, roman_value("L"));
  ck_assert_int_eq(100, roman_value("C"));
  ck_assert_int_eq(500, roman_value("D"));
  ck_assert_int_eq(1000, roman_value("M"));
}
END_TEST

START_TEST (test_roman_values_additive)
{
  ck_assert_int_eq(2, roman_value("II"));
  ck_assert_int_eq(3, roman_value("III"));
  ck_assert_int_eq(6, roman_value("VI"));
  //ck_assert_int_eq(1000, roman_value("Mxs"));
}
END_TEST

START_TEST (test_roman_values_lesser_subtract)
{
  ck_assert_int_eq(4, roman_value("IV"));
  ck_assert_int_eq(9, roman_value("IX"));
  ck_assert_int_eq(99, roman_value("IC"));  // TODO add test to fix this (invalid)
}
END_TEST

Suite * roman_to_int_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals");
    tc_core = tcase_create("roman-values");

    tcase_add_test(tc_core, test_roman_values);
    tcase_add_test(tc_core, test_roman_values_additive);
    tcase_add_test(tc_core, test_roman_values_lesser_subtract);
    suite_add_tcase(s, tc_core);

    return s;
}
