#ifndef STRINGS_H
#define STRINGS_H

#include "bool.h"

char get_first(char *roman_letters);
char get_second(char *roman_letters);
bool exists_first(char *roman_letters);
bool exists_second(char *roman_letters);
int count_consecutive(char* str, char c);
int count_numeral(char* str, char c);

#endif
