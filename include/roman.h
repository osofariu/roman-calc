#include <stdio.h>
#include "bool.h"
#include "strings.h"

int roman_value(char *roman_str);

struct RomanLetter {
  char letter;
  int value;
};
  
