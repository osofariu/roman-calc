#include <stdio.h>
#include "roman.h"

struct RomanLetter letter_I = {'I',  1};

int lookup_roman_letter(char letter) {
  if (letter == letter_I.letter) {
    return letter_I.value;
  }
  return 0;
}

int roman_value(char *roman_str) {
  int val = 0;
  while (*roman_str != '\0') {
    val += lookup_roman_letter(*roman_str);
    roman_str++;
  }
  return val;
}
