#include <stdlib.h>

char uppercase(const char *character);
char lowercase(const char *character);

void to_camel_case(const char *text, char *camel) {

  for (int i = 0; text[i]; i++) {
    if (text[i] == '_' || text[i] == '-') {
      i++;
      *camel = uppercase(text + i);
    } else {
      if (i == 0) {
        *camel = text[i];
      } else {
        *camel = lowercase(text + i);
      }
    }
    camel++;
  }
  *camel = '\0';
}

char uppercase(const char *character) {
  if (*character >= 'a' && *character <= 'z')
    return *character - ' ';
  else
    return *character;
}

char lowercase(const char *character) {
  if (*character >= 'A' && *character <= 'Z')
    return *character + ' ';
  else
    return *character;
}