#include <ctype.h>
#include <stdlib.h>

void to_camel_case(const char *text, char *camel) {

  for (int i = 0; text[i]; i++) {
    if (text[i] == '_' || text[i] == '-') {
      *(camel++) = toupper(text[++i]);
    } else
      *(camel++) = text[i];
  }
  *camel = '\0';
}