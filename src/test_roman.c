#include <check.h>
#include <stdlib.h>
#include "roman.h"

START_TEST (test_roman_values)
{
  ck_assert_int_eq(1, roman_value("I"));
  ck_assert_int_eq(2, roman_value("II"));
  ck_assert_int_eq(3, roman_value("III"));
  ck_assert_int_eq(5, roman_value("V"));
  ck_assert_int_eq(10, roman_value("X"));
  ck_assert_int_eq(50, roman_value("L"));
  ck_assert_int_eq(100, roman_value("C"));
}
END_TEST


Suite * roman_numerals_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals");
    tc_core = tcase_create("roman-values");

    tcase_add_test(tc_core, test_roman_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(int argc, char* argv[]) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numerals_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
