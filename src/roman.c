#include <stdio.h>
#include "roman.h"

struct RomanLetter romanLetters[] = {
  {'I',  1},{'V', 5}
};


int lookup_roman_letter(char letter) {
  int letter_ct;
  for (letter_ct = 0; letter_ct < sizeof(romanLetters); letter_ct++) {
    struct RomanLetter roman_letter = romanLetters[letter_ct];
    if (letter == roman_letter.letter) {
      return roman_letter.value;
    }
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
