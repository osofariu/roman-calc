#include "roman_calculator.h"
#include "roman_to_int.h"
#include "int_to_roman.h"
#include "roman_validation.h"

int calc_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message, int op_direction) {

  bool result;
  strcpy(resultNumeral, "");

  result = validate_roman_numeral(firstNumeral, message); 
  if (result != CODE_SUCCESS) 
    return result;

  result = validate_roman_numeral(secondNumeral, message);
  if (result != CODE_SUCCESS) 
    return result;

  int numericResult = roman_value(firstNumeral) + op_direction * roman_value(secondNumeral);
  if (numericResult <= 0) {
    strcpy(message, "Subtracting two roman numerals must result in a positive numeral");
    return CODE_NEGATIVE_RESULT;
  } else {
    int_to_roman_numeral(numericResult, resultNumeral);
    result = validate_roman_numeral(resultNumeral, message); 
    if (result != CODE_SUCCESS) {
      strcpy(resultNumeral, "");
      return result;
    }
  }  
  return CODE_SUCCESS;
}

int add_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message) {
  return calc_roman_numerals(firstNumeral, secondNumeral, resultNumeral, message, 1);
}

int subtract_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char *message) {
  return calc_roman_numerals(firstNumeral, secondNumeral, resultNumeral, message, -1);
}
