#include "roman_calculator.h"
#include "roman_to_int.h"
#include "int_to_roman.h"

char* add_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral) {
  int sum = roman_value(firstNumeral) + roman_value(secondNumeral);
  return roman_numeral(sum, resultNumeral);
}
