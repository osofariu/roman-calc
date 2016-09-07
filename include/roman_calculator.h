#ifndef FILE_ROMAN_CALCULATOR_H
#define FILE_ROMAN_CALCULATOR_H

#include<check.h>

Suite* roman_calculator_suite(void);
int add_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char* message);
int subtract_roman_numerals(char* firstNumeral, char* secondNumeral, char *resultNumeral, char* message);
#endif
