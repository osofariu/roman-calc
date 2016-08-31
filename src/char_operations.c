#include "bool.h"

char get_first(char *letters) {
  return *letters;
}

char get_second(char *letters) {
  return *(letters+1);
}

bool exists_first(char *letters) {
  if (get_first(letters) != '\0')
    return true;
  return false;
}

bool exists_second(char *letters) {
  if ((*letters != '\0') && (*(letters+1) != '\0')) return true;
  return false;
}
