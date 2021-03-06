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
 
START_TEST (test_count_consecutive_numeral)
{
  ck_assert_int_eq(1, count_consecutive("IX", 'I'));
  ck_assert_int_eq(0, count_consecutive("IX", 'Y'));
  ck_assert_int_eq(4, count_consecutive("IIII", 'I'));
  ck_assert_int_eq(4, count_consecutive("XIIIIX", 'I'));
}
END_TEST

START_TEST (test_count_consecutive_numeral_with_others)
{
  ck_assert_int_eq(4, count_consecutive("IXIIIIXI", 'I'));
}
END_TEST

START_TEST (test_count_numeral)
{
  ck_assert_int_eq(6, count_numeral("IXIIIIXI", 'I'));
  ck_assert_int_eq(0, count_numeral("ABC", 'D'));
}
END_TEST

Suite * char_operations_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Char Operations");
    tc_core = tcase_create("char-ops");

    tcase_add_test(tc_core, test_exists_first);
    tcase_add_test(tc_core, test_get_first);
    tcase_add_test(tc_core, test_exists_second);
    tcase_add_test(tc_core, test_get_second);
    tcase_add_test(tc_core, test_count_consecutive_numeral);
    tcase_add_test(tc_core, test_count_consecutive_numeral_with_others);
    tcase_add_test(tc_core, test_count_numeral);
    suite_add_tcase(s, tc_core);

    return s;
}

