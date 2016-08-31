#include "bool.h"
#include "roman_validation.h"
#include "char_operations.h"

bool validate_consecutive_chars(char* romanNumeral, char c, int max_repeating, char* message) {
  int count = count_consecutive(romanNumeral, c);
  if (count > max_repeating) {
    strcpy(message, "Invalid roman numeral: too many consecutive ");
    char numeral[2];
    numeral[0] = c;
    numeral[1] = '\0';
    strcpy(message + strlen(message), numeral);
    return false;
  }
  return true;
}

bool validate_roman_numeral(char* romanNumeral, char* message) {
  char numerals[] ="IXC";
  int i;
  for (i = 0; i < sizeof(numerals); i++) {
    bool result = validate_consecutive_chars(romanNumeral, numerals[i], 3, message); 
    if (result == false)
      return false;
  }
  return true;
}
