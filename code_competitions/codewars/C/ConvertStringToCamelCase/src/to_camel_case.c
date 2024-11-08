#include <ctype.h>
#include <stdlib.h>

void to_camel_case(const char *text, char *camel) {
  if (text == NULL || camel == NULL)
    return;

  while (*text) {
    if (*text == '_' || *text == '-') {
      text++;
      if (*text) {
        *camel++ = toupper((unsigned char)*text);
      }
    } else {
      *camel++ = *text;
    }
    text++;
  }
  *camel = '\0';
}