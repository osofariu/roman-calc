#include "bool.h"
#include "roman_validation.h"
#include "char_operations.h"
#include "roman_to_int.h"

bool validate_consecutive_char_ct(char* roman_numeral, char c, int max_repeating, char* message) {
  int count = count_consecutive(roman_numeral, c);
  if (count > max_repeating) {
    strcpy(message, "Invalid roman numeral: too many consecutive I, X, or C");
    return false;
  }
  return true;
}


bool validate_consecutive_ixc_ct(char* roman_numeral, char* message) {
  if (validate_consecutive_char_ct(roman_numeral, 'I', 3, message) == false) return false; 
  if (validate_consecutive_char_ct(roman_numeral, 'X', 3, message) == false) return false;
  if (validate_consecutive_char_ct(roman_numeral, 'C', 3, message) == false) return false;
  return true;
}


bool validate_char_ct(char* roman_numeral, char c, int max_count, char* message) {
  int count = count_numeral(roman_numeral, c);
  if (count > max_count) {
    strcpy(message, "Invalid roman numeral: more than one consecutive V, L, or D");
    return false;
  }
  return true;
}

bool validate_vld_ct(char *roman_numeral, char *message) {
  if (validate_char_ct(roman_numeral, 'V', 1, message) == false) return false; 
  if (validate_char_ct(roman_numeral, 'L', 1, message) == false) return false; 
  if (validate_char_ct(roman_numeral, 'D', 1, message) == false) return false; 
  return true;
}
  

bool validate_max_numeral(char* roman_numeral, char *message) {
  int romanValue = roman_value(roman_numeral);
  if (romanValue > 3999) {
    strcpy(message, "Roman numeral too large.");
    return false;
  }
  strcpy(message, "");
  return true;
}

bool validate_roman_numeral(char* roman_numeral, char* message) {
  if (validate_consecutive_ixc_ct(roman_numeral, message) == false) return false;
  if (validate_vld_ct(roman_numeral, message) == false) return false;
  if (validate_max_numeral(roman_numeral, message) == false) return false;
  return true;
}
