#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "roman_to_int.h"
#include "int_to_roman.h"
#include "roman_calculator.h"
#include "roman_validation.h"
#include "char_operations.h"
#include "test_roman_runner.h"
#include "roman.h"

int main(int argc, char* argv[]) {
  
  if (argc == 4 && ((strcmp(argv[1], "+") == 0) || (strcmp(argv[1], "-") == 0))) {
    char* operation = argv[1];
    char* firstRoman = argv[2];
    char* secondRoman = argv[3];
    char message[MAX_MESSAGE_SIZE] = "";
    char sumResult[MAX_NUMERAL_SIZE] = "";

    int result;
    if (strcmp(operation, "+") == 0)
      result = add_roman_numerals(firstRoman, secondRoman, sumResult, message);
    else
      result = subtract_roman_numerals(firstRoman, secondRoman, sumResult, message);
    
    if (result == CODE_SUCCESS) 
      printf("%s %s %s = %s\n", firstRoman, operation, secondRoman, sumResult);
    else {
      fprintf(stderr, "%s\n", message);
    }
  }
  
  else if (argc == 2 && strcmp(argv[1], "tests") == 0) {
    int number_failed;
    SRunner* sr = srunner_create(roman_calculator_suite());
    srunner_add_suite(sr, roman_to_int_suite());
    srunner_add_suite(sr, int_to_roman_suite());
    srunner_add_suite(sr, roman_validation_suite());
    srunner_add_suite(sr, char_operations_suite());
    srunner_add_suite(sr, roman_runner_suite());
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  }
  else {
    fprintf(stderr, "Usage: roman_runner [+ num num | - num num]\n");
    return -1;
  }
}
