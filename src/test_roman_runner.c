#include <check.h>
#include <stdlib.h>
#include "roman_to_int.h"
#include "int_to_roman.h"
#include "roman_calculator.h"
#include "roman_validation.h"

int main(int argc, char* argv[]) {
    int number_failed;
    SRunner* sr = srunner_create(roman_to_int_suite());
    srunner_add_suite(sr, int_to_roman_suite());
    srunner_add_suite(sr, roman_calculator_suite());
    srunner_add_suite(sr, roman_validation_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
