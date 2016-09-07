#include <check.h>
#include "roman_validation.h"
#include "bool.h"
#include "roman.h"

START_TEST (test_validate_max_repeating_ixc)
{
  char validationMessage[MAX_MESSAGE_SIZE];
  ck_assert_int_eq(false, validate_roman_numeral("IIII", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive I, X, or C", validationMessage); 
  
  ck_assert_int_eq(false, validate_roman_numeral("XXXX", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive I, X, or C", validationMessage); 
  
  ck_assert_int_eq(false, validate_roman_numeral("CCCC", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: too many consecutive I, X, or C", validationMessage); 

  ck_assert_int_eq(true, validate_roman_numeral("III", validationMessage));
  ck_assert_str_eq("", validationMessage); 
}
END_TEST


START_TEST (test_validate_max_count_vld)
{
  char validationMessage[MAX_MESSAGE_SIZE];
  ck_assert_int_eq(false, validate_roman_numeral("VV", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: more than one consecutive V, L, or D", validationMessage);

  ck_assert_int_eq(false, validate_roman_numeral("LL", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: more than one consecutive V, L, or D", validationMessage);

  ck_assert_int_eq(false, validate_roman_numeral("DD", validationMessage));
  ck_assert_str_eq("Invalid roman numeral: more than one consecutive V, L, or D", validationMessage);

  ck_assert_int_eq(true, validate_roman_numeral("DLV", validationMessage));
  ck_assert_str_eq("", validationMessage);
}
END_TEST

START_TEST (test_validate_max_numeral)
{
  char validationMessage[MAX_MESSAGE_SIZE];

  ck_assert_int_eq(false, validate_roman_numeral("MMMM", validationMessage));
  ck_assert_str_eq("Roman numeral too large.", validationMessage);
  
  ck_assert_int_eq(true, validate_roman_numeral("MMMCMXCIX", validationMessage));
  ck_assert_str_eq("", validationMessage);
}
END_TEST

START_TEST (test_validate_roman_numerals)
{
  char validationMessage[MAX_MESSAGE_SIZE];
  ck_assert_int_eq(false, validate_roman_numeral("Z", validationMessage));
  ck_assert_str_eq("Roman numeral contains invalid characters", validationMessage);

  ck_assert_int_eq(true, validate_roman_numeral("MDCLXVI", validationMessage));
  ck_assert_str_eq("", validationMessage);

}
END_TEST


Suite* roman_validation_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Validate Roman Numeral");
    tc_core = tcase_create("validate-roman");

    tcase_add_test(tc_core, test_validate_max_repeating_ixc);
    tcase_add_test(tc_core, test_validate_max_count_vld);
    tcase_add_test(tc_core, test_validate_max_numeral);
    tcase_add_test(tc_core, test_validate_roman_numerals);
    
    suite_add_tcase(s, tc_core);

    return s;
}




