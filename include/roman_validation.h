#ifndef FILE_ROMAN_VALIDATION_H
#define FILE_ROMAN_VALIDATION_H

#include "bool.h"
#include <check.h>

Suite* roman_validation_suite(void);
bool validate_roman_numeral(char* romanNumeral, char* message);

#endif
