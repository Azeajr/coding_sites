#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_ip(const char *addr) {
  size_t addr_len = strlen(addr);

  // Check overall length
  if (addr_len < 7 || addr_len > 15) {
    return false;
  }

  // Check for invalid starting or ending characters
  if (addr[0] == '.' || addr[addr_len - 1] == '.') {
    return false;
  }

  // Check for consecutive dots or non-digit characters
  for (size_t i = 0; i < addr_len; i++) {
    if (!isdigit((unsigned char)addr[i]) && addr[i] != '.') {
      return false;
    }
    if (addr[i] == '.' && addr[i + 1] == '.') {
      return false;
    }
  }

  char buffer[16];
  strncpy(buffer, addr, 15);
  buffer[15] = '\0';

  char *saveptr;
  char *token = strtok_r(buffer, ".", &saveptr);
  int octetCount = 0;

  while (token) {
    // Check for empty tokens(consecutive dots or leading/trailing dots)
    printf("token(%ld):\t%s\n", strlen(token), token);
    if (strlen(token) == 0) {
      return false;
    }

    // Check for leading zeros
    if (token[0] == '0' && token[1] != '\0') {
      return false;
    }

    // Convert token to number
    long octet = strtol(token, NULL, 10);

    // Check octet range
    if (octet < 0 || octet > 255) {
      return false;
    }
    octetCount++;
    token = strtok_r(NULL, ".", &saveptr);
  }

  return octetCount == 4;
}
