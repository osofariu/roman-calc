#include <stdio.h>
#include <check.h>
#include "roman.h"
#include "roman_to_int.h"
#include "char_operations.h"
#include "bool.h"

const struct RomanLetter romanLetters[] = {
  {'I',  1},{'V', 5},{'X', 10},{'L', 50}, {'C', 100},{'D', 500},{'M', 1000}
};


int lookup_roman_letter_value(char letter) {
  int letter_ct;
  for (letter_ct = 0; letter_ct < sizeof(romanLetters); letter_ct++) {
    struct RomanLetter roman_letter = romanLetters[letter_ct];
    
    if (letter == roman_letter.letter) {
      return roman_letter.value;
    }
  }
  return 0;
}

bool current_letter_subtracts_next(char *roman_letters) {
  if ((exists_first(roman_letters) && (exists_second(roman_letters)) && 
       (lookup_roman_letter_value(get_first(roman_letters)) <
        lookup_roman_letter_value(get_second(roman_letters)))))
    return true;
  return false;
}

int value_of_roman_numeral(char *roman_str) {
  int val = 0;
  while (exists_first(roman_str)) {
    if (current_letter_subtracts_next(roman_str) == true)
      val -= lookup_roman_letter_value(get_first(roman_str));
    else 
      val += lookup_roman_letter_value(get_first(roman_str));
    roman_str++;
  }
  return val;
}
