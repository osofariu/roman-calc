#include "roman_calculator.h"
#include "roman_to_int.h"
#include "int_to_roman.h"
#include "roman_validation.h"

char* calc_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message, int op_direction) {
  if (validate_roman_numeral(firstNumeral, message) == false) {
    strcpy(resultNumeral, "");
    return("");
  }

  if (validate_roman_numeral(secondNumeral, message) == false) {
    strcpy(resultNumeral, "");
    return("");
  }

  int sum = roman_value(firstNumeral) + op_direction * roman_value(secondNumeral);
  int_to_roman_numeral(sum, resultNumeral);
  if (validate_roman_numeral(resultNumeral, message) == false) {
    strcpy(resultNumeral, "");
    return("");
  } else {
    return resultNumeral;
  }
}

char* add_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message) {
  return calc_roman_numerals(firstNumeral, secondNumeral, resultNumeral, message, 1);
}

char* subtract_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message) {
  return calc_roman_numerals(firstNumeral, secondNumeral, resultNumeral, message, -1);
}
