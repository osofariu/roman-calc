#include "bool.h"
#include "roman_validation.h"
#include "char_operations.h"

bool validate_roman_numeral(char* romanNumeral, char* message) {
  int count = count_consecutive(romanNumeral, 'I');
  if (count > 3) {
    strcpy(message, "Invalid roman numeral: too many consecutive I");
    return false;
  }
  return true;
}
