#include <stdlib.h>
#include "int_to_roman.h"
#include "roman.h"

struct RomanNumeral {
  int value;
  char *chars;
};

const struct RomanNumeral romanNumeralGroups[] = {
  {1000, "M"}, {900, "CM"}, {1000, "D"},  {500, "D"},  {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},  {9, "IX"},  {5, "V"}, {4, "IV"},  {1, "I"} 
};

char *int_to_roman_numeral(int numeralValue, char* romanNumeralOutput) { 
  char *outputPtr = romanNumeralOutput;
  while (numeralValue > 0) {
    int i;
    int max_i = sizeof(romanNumeralGroups)/sizeof(romanNumeralGroups[0]);
    for (i = 0; i < max_i; i++) {
      struct RomanNumeral currentNumeral = romanNumeralGroups[i];
      if (numeralValue >= currentNumeral.value) {
        strcpy(outputPtr, currentNumeral.chars);
        outputPtr += strlen(currentNumeral.chars);
        numeralValue -= currentNumeral.value;
        break;
      }
    }
  }
  
  return romanNumeralOutput;
}
