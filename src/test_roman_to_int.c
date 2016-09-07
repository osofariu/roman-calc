#include <check.h>
#include "roman_to_int.h"

START_TEST (test_value_of_roman_numerals)
{
  ck_assert_int_eq(1, value_of_roman_numeral("I"));
  ck_assert_int_eq(5, value_of_roman_numeral("V"));
  ck_assert_int_eq(10, value_of_roman_numeral("X"));
  ck_assert_int_eq(50, value_of_roman_numeral("L"));
  ck_assert_int_eq(100, value_of_roman_numeral("C"));
  ck_assert_int_eq(500, value_of_roman_numeral("D"));
  ck_assert_int_eq(1000, value_of_roman_numeral("M"));
}
END_TEST

START_TEST (test_value_of_roman_numerals_additive)
{
  ck_assert_int_eq(2, value_of_roman_numeral("II"));
  ck_assert_int_eq(3, value_of_roman_numeral("III"));
  ck_assert_int_eq(6, value_of_roman_numeral("VI"));
}
END_TEST

START_TEST (test_value_of_roman_numerals_lesser_subtract)
{
  ck_assert_int_eq(4, value_of_roman_numeral("IV"));
  ck_assert_int_eq(9, value_of_roman_numeral("IX"));
  ck_assert_int_eq(99, value_of_roman_numeral("IC"));  // TODO add test to fix this (invalid)
}
END_TEST

Suite * roman_to_int_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman To Int");
    tc_core = tcase_create("roman-to-int");

    tcase_add_test(tc_core, test_value_of_roman_numerals);
    tcase_add_test(tc_core, test_value_of_roman_numerals_additive);
    tcase_add_test(tc_core, test_value_of_roman_numerals_lesser_subtract);
    suite_add_tcase(s, tc_core);

    return s;
}
