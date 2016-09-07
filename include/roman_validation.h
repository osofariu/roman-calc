#ifndef FILE_ROMAN_VALIDATION_H
#define FILE_ROMAN_VALIDATION_H

#include "bool.h"
#include <check.h>

Suite* roman_validation_suite(void);
bool validate_roman_numeral(char* romanNumeral, char* message);

#define CODE_SUCCESS 0

#define MSG_INVALID_CONSECUTIVE_IXC "Invalid roman numeral: too many consecutive I, X, or C"
#define CODE_INVALID_CONSECUTIVE_IXC 1

#define MSG_INVALID_CONSECUTIVE_VLD "Invalid roman numeral: more than one consecutive V, L, or D"
#define CODE_INVALID_CONSECUTIVE_VLD 2

#define MSG_INVALID_MAX_NUMERAL  "Roman numeral too large"
#define CODE_INVALID_MAX_NUMERAL 3

#define MSG_INVALID_NUMERAL_CHAR "Roman numeral contains invalid characters"
#define CODE_INVALID_NUMERAL_CHAR 4

#define CODE_NEGATIVE_RESULT 5

#endif
