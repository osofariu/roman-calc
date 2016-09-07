#include <string.h>
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
  strcpy(message, "");
  int romanValue = value_of_roman_numeral(roman_numeral);
  return (romanValue <= 3999); 
}

bool validate_roman_numeral_letters(char *roman_numeral, char* message) {
  char validChars[] = "IVXLCDM";
  int i;
  for (i = 0; i < strlen(roman_numeral); i++) {
    if (strchr(validChars, roman_numeral[i]) == NULL) {
      strcpy(message, "Roman numeral contains invalid characters");
      return false;
    }
  }
  strcpy(message, "");
  return(true);
}

int validate_roman_numeral(char* roman_numeral, char* message) {
  int validationCode;
  
  validationCode = validate_roman_numeral_letters(roman_numeral, message);
  if (validationCode != true) {
    strcpy(message, MSG_INVALID_NUMERAL_CHAR);
    return CODE_INVALID_NUMERAL_CHAR;
  }
  validationCode = validate_consecutive_ixc_ct(roman_numeral, message); 
  if (validationCode != true) {
    strcpy(message, MSG_INVALID_CONSECUTIVE_IXC);
    return CODE_INVALID_CONSECUTIVE_IXC; 
  }
  validationCode = validate_vld_ct(roman_numeral, message);
  if (validationCode != true) {
    strcpy(message, MSG_INVALID_CONSECUTIVE_VLD);
    return CODE_INVALID_CONSECUTIVE_VLD; 
  }

  validationCode = validate_max_numeral(roman_numeral, message);
  if (validationCode != true) {
    strcpy(message, MSG_INVALID_MAX_NUMERAL);
    return CODE_INVALID_MAX_NUMERAL; 
  }
  
  return CODE_SUCCESS;
}

