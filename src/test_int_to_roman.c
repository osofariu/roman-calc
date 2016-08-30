#include <check.h>
#include <stdlib.h>
#include "int_to_roman.h"

START_TEST (test_int_to_single_roman_letter)
{
  char expectedNumeral[50] = "";
  ck_assert_str_eq("I", roman_numeral(1, expectedNumeral));
  ck_assert_str_eq("M", roman_numeral(1000, expectedNumeral));
}
END_TEST

Suite* int_to_roman_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Int to Roman");
    tc_core = tcase_create("int-to-roman");

    tcase_add_test(tc_core, test_int_to_single_roman_letter);
    suite_add_tcase(s, tc_core);

    return s;
}
