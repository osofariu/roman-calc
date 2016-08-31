#include <check.h>
#include <stdlib.h>
#include "char_operations.h"
#include "bool.h"

/*

char get_second(char *roman_letters);
bool exists_first(char *roman_letters);
bool exists_second(char *roman_letters);
 */

START_TEST (test_exists_first)
{
  ck_assert_int_eq(true, exists_first("X")); 
  ck_assert_int_eq(false, exists_first(""));
}
END_TEST

START_TEST (test_get_first)
{
  ck_assert_int_eq('X', get_first("XYZ")); 
  ck_assert_int_eq(' ', get_first(" foo"));
}
END_TEST

START_TEST (test_exists_second)
{
  ck_assert_int_eq(true, exists_second("XY")); 
  ck_assert_int_eq(false, exists_second("X"));
  ck_assert_int_eq(false, exists_second(""));
}
END_TEST

START_TEST (test_get_second)
{
  ck_assert_int_eq('Y', get_second("XYZ")); 
  ck_assert_int_eq(' ', get_second("X Z")); 
}
END_TEST

Suite * strings_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("String Operations");
    tc_core = tcase_create("string-ops");

    tcase_add_test(tc_core, test_exists_first);
    tcase_add_test(tc_core, test_get_first);
    tcase_add_test(tc_core, test_exists_second);
    tcase_add_test(tc_core, test_get_second);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(int argc, char* argv[]) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strings_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
