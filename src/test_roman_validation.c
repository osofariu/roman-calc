#include <check.h>
#include "roman_validation.h"
#include "bool.h"

START_TEST (test_validate_max_repeating_i)
{
  char validationMessage[100] = "";
  ck_assert_int_eq(false, validate_roman_numeral("IIII", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive I", validationMessage); 
}
END_TEST

Suite* roman_validation_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Validate Roman Numeral");
    tc_core = tcase_create("validate-roman");

    tcase_add_test(tc_core, test_validate_max_repeating_i);
    suite_add_tcase(s, tc_core);

    return s;
}




