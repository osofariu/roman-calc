#include <stdio.h>
#include "roman.h"

struct RomanLetter romanLetters[] = {
  {'I',  1},{'V', 5},{'X', 10},{'L', 50}, {'C', 100},{'D', 500},{'M', 1000}
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

bool current_letter_subtracts(char current_letter, char next_letter) {
  if (lookup_roman_letter(current_letter) < lookup_roman_letter(next_letter))
    return true;
  return false;
}

int roman_value(char *roman_str) {
  int val = 0;
  while (*roman_str != '\0') {
    if ((*(roman_str + 1) != '\0') && (current_letter_subtracts(*roman_str, *(roman_str+1)) == true))
      val -= lookup_roman_letter(*roman_str);
    else 
      val += lookup_roman_letter(*roman_str);
    roman_str++;
  }
  return val;
}
