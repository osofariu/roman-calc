#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "roman_to_int.h"
#include "int_to_roman.h"
#include "roman_calculator.h"
#include "roman_validation.h"

int main(int argc, char* argv[]) {

  if (argc == 4 && strcmp(argv[1], "+") == 0) {
    char* firstRoman = argv[2];
    char* secondRoman = argv[3];
    char addResult[50];

    add_roman_numerals(firstRoman, secondRoman, addResult);
    printf("%s + %s = %s\n", firstRoman, secondRoman, addResult);
  }
  
  else if (argc == 4 && strcmp(argv[1], "-") == 0) {

  }

  else if (argc == 2 && strcmp(argv[1], "tests") == 0) {
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
  else {
    printf("Usage: test_roman_runner [+ num num | - num num]\n");
    return -1;
  }
}
