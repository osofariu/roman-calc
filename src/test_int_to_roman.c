#include <check.h>
#include "int_to_roman.h"

START_TEST (test_int_to_single_roman_numeral_group)
{
  char expectedNumeral[50] = "";
  ck_assert_str_eq("I", roman_numeral(1, expectedNumeral));
  ck_assert_str_eq("IV", roman_numeral(4, expectedNumeral));
  ck_assert_str_eq("V", roman_numeral(5, expectedNumeral));
  ck_assert_str_eq("IX", roman_numeral(9, expectedNumeral));
  ck_assert_str_eq("X", roman_numeral(10, expectedNumeral));
  ck_assert_str_eq("XL", roman_numeral(40, expectedNumeral));
  ck_assert_str_eq("L", roman_numeral(50, expectedNumeral));
  ck_assert_str_eq("XC", roman_numeral(90, expectedNumeral));
  ck_assert_str_eq("C", roman_numeral(100, expectedNumeral));
  ck_assert_str_eq("CD", roman_numeral(400, expectedNumeral));
  ck_assert_str_eq("D", roman_numeral(500, expectedNumeral));
  ck_assert_str_eq("CM", roman_numeral(900, expectedNumeral));
  ck_assert_str_eq("M", roman_numeral(1000, expectedNumeral));
}
END_TEST

START_TEST (test_int_to_compound_roman_numeral_groups)
{
  char expectedNumeral[50] = "";
  ck_assert_str_eq("MMXVI", roman_numeral(2016, expectedNumeral));
  ck_assert_str_eq("MCMXCIV", roman_numeral(1994, expectedNumeral));
  ck_assert_str_eq("MMMCMXCIX", roman_numeral(3999, expectedNumeral));
}
END_TEST

Suite* int_to_roman_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Int to Roman");
    tc_core = tcase_create("int-to-roman");

    tcase_add_test(tc_core, test_int_to_single_roman_numeral_group);
    tcase_add_test(tc_core, test_int_to_compound_roman_numeral_groups);
    suite_add_tcase(s, tc_core);

    return s;
}
