#ifndef FILE_CHAR_OPERATIONS_H
#define FILE_CHAR_OPERATIONS_H

#include "bool.h"
#include <check.h>

char get_first(char *roman_letters);
char get_second(char *roman_letters);
bool exists_first(char *roman_letters);
bool exists_second(char *roman_letters);
int count_consecutive(char* str, char c);
int count_numeral(char* str, char c);

Suite * char_operations_suite(void);

#endif
