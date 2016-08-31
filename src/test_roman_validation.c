#include <check.h>
#include "roman_validation.h"
#include "bool.h"

START_TEST (test_validate_max_repeating_ixc)
{
  char validationMessage[100] = "";
  ck_assert_int_eq(false, validate_roman_numeral("IIII", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive I", validationMessage); 
  
  ck_assert_int_eq(false, validate_roman_numeral("XXXX", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive X", validationMessage); 
  
  ck_assert_int_eq(false, validate_roman_numeral("CCCC", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive C", validationMessage); 
}
END_TEST


START_TEST (test_validate_max_repeating_ixc_ok)
{
  char validationMessage[100] = "";
  ck_assert_int_eq(true, validate_roman_numeral("III", validationMessage));
  ck_assert_str_eq("", validationMessage); 
}
END_TEST

Suite* roman_validation_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Validate Roman Numeral");
    tc_core = tcase_create("validate-roman");

    tcase_add_test(tc_core, test_validate_max_repeating_ixc);
    tcase_add_test(tc_core, test_validate_max_repeating_ixc_ok);

    
    suite_add_tcase(s, tc_core);

    return s;
}




