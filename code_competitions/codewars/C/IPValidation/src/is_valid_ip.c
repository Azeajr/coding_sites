#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * Validates whether the given string is a valid IPv4 address.
 *
 * @param addr The string representing the IP address to validate.
 * @return 1 if valid, 0 otherwise.
 */
int is_valid_ip(const char *addr) {
  if (addr == NULL) {
    return 0;
  }

  // Quick length check: Minimum 7 ("0.0.0.0"), Maximum 15 ("255.255.255.255")
  size_t len = strlen(addr);
  if (len < 7 || len > 15) {
    return 0;
  }

  unsigned int octets[4];
  int chars_consumed = 0;

  // Attempt to parse the four octets and capture the number of characters read
  if (sscanf(addr, "%u.%u.%u.%u%n", &octets[0], &octets[1], &octets[2],
             &octets[3], &chars_consumed) != 4) {
    return 0;
  }

  // Ensure that the entire string was consumed by sscanf (no extra characters)
  if (chars_consumed != (int)len) {
    return 0;
  }

  // Validate each octet's range
  for (int i = 0; i < 4; i++) {
    if (octets[i] > 255) {
      return 0;
    }
  }

  // Pointer to traverse the string again for leading zero checks
  const char *ptr = addr;

  for (int i = 0; i < 4; i++) {
    int octet_length = 0;

    // Calculate the length of the current octet
    while (ptr[octet_length] && ptr[octet_length] != '.') {
      // Early exit if non-digit characters are present
      if (!isdigit((unsigned char)ptr[octet_length])) {
        return 0;
      }
      octet_length++;
    }

    // Check for empty octet or octet length exceeding 3 digits
    if (octet_length == 0 || octet_length > 3) {
      return 0;
    }

    // Check for leading zeros in multi-digit octets
    if (octet_length > 1 && ptr[0] == '0') {
      return 0;
    }

    // Move the pointer to the start of the next octet
    ptr += octet_length;

    // If not the last octet, ensure there's a dot separator
    if (i < 3) {
      if (*ptr != '.') {
        return 0;
      }
      ptr++; // Skip the dot
    }
  }

  return 1;
}
