#include <check.h>
#include <stdlib.h>
#include "char_operations.h"
#include "bool.h"

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
 
START_TEST (test_count_consecutive)
{
  ck_assert_int_eq(1, count_consecutive("IX", 'I'));
  ck_assert_int_eq(0, count_consecutive("IX", 'Y'));
  ck_assert_int_eq(4, count_consecutive("IIII", 'I'));
  ck_assert_int_eq(4, count_consecutive("XIIIIX", 'I'));
}
END_TEST

START_TEST (test_count_consecutive_with_others)
{
  ck_assert_int_eq(4, count_consecutive("IXIIIIXI", 'I'));
}
END_TEST

Suite * char_operations_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("String Operations");
    tc_core = tcase_create("string-ops");

    tcase_add_test(tc_core, test_exists_first);
    tcase_add_test(tc_core, test_get_first);
    tcase_add_test(tc_core, test_exists_second);
    tcase_add_test(tc_core, test_get_second);
    tcase_add_test(tc_core, test_count_consecutive);
    tcase_add_test(tc_core, test_count_consecutive_with_others);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(int argc, char* argv[]) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = char_operations_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
