#include <stdlib.h>
#include "int_to_roman.h"
#include "roman.h"

char *roman_numeral(int numeralValue, char* romanNumeralOutput) { 
  char *outputPtr = romanNumeralOutput;
  while (numeralValue > 0) {
    if (numeralValue >= 1000) {
      strcpy(outputPtr, "M");
      outputPtr += 1;
      numeralValue -= 1000;
    }
    else if (numeralValue >= 1) {
      strcpy(outputPtr, "I");
      outputPtr +=1;
      numeralValue -= 1;
    }
  }
  
  return romanNumeralOutput;
}
