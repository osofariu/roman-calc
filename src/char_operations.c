#include "bool.h"
#include <string.h>

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

int count_consecutive(char* str, char c) {
  int current_count = 0;
  int max_count = 0;
  int i;
  bool currently_matching = false;
  for (i=0; i < strlen(str); i++) {
    if (str[i] == c) {
      current_count++;
      currently_matching = true;
    }
    else {
      currently_matching = false;
      current_count = 0;
    }
    if (current_count > max_count) {
      max_count = current_count;
    }
  }
  return max_count;
}
