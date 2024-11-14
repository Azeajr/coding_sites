#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

/**
 * Validates whether the given string is a valid IPv4 address.
 *
 * @param addr The string representing the IP address to validate.
 * @return 1 if valid, 0 otherwise.
 */
// Implementation 1: Direct Integer Parsing
int is_valid_ip_v1(const char *addr) {
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

// Implementation 2: String Extraction
int is_valid_ip_v2(const char *addr) {
  if (addr == NULL) {
    return 0;
  }

  size_t len = strlen(addr);
  if (len < 7 || len > 15) {
    return 0;
  }

  char octet1[4], octet2[4], octet3[4], octet4[4];
  int chars_consumed = 0;

  int result = sscanf(addr, "%3[0-9].%3[0-9].%3[0-9].%3[0-9]%n", octet1, octet2,
                      octet3, octet4, &chars_consumed);

  if (result != 4) {
    return 0;
  }

  if (chars_consumed != (int)len) {
    return 0;
  }

  const char *octets[4] = {octet1, octet2, octet3, octet4};

  for (int i = 0; i < 4; i++) {
    const char *octet = octets[i];
    size_t octet_len = strlen(octet);

    if (octet_len == 0 || octet_len > 3) {
      return 0;
    }

    if (octet_len > 1 && octet[0] == '0') {
      return 0;
    }

    int num = 0;
    for (size_t j = 0; j < octet_len; j++) {
      if (!isdigit((unsigned char)octet[j])) {
        return 0;
      }
      num = num * 10 + (octet[j] - '0');
    }

    if (num > 255) {
      return 0;
    }
  }

  return 1;
}
// Implementation 3: Manual Parsing
int is_valid_ip_v3(const char *addr) {
    if (addr == NULL) {
        return 0;
    }

    int num = 0;
    int dots = 0;
    const char *ptr = addr;
    const char *start = addr;

    while (*ptr) {
        if (*ptr == '.') {
            // Empty octet (consecutive dots or leading/trailing dot)
            if (ptr == start) {
                return 0;
            }
            // Leading zero in octet (except for zero itself)
            if (start[0] == '0' && ptr - start > 1) {
                return 0;
            }
            // Octet value out of range
            if (num < 0 || num > 255) {
                return 0;
            }
            dots++;
            if (dots > 3) {
                return 0;
            }
            num = 0;
            ptr++;
            start = ptr;
            continue;
        }

        if (!isdigit((unsigned char)*ptr)) {
            return 0;
        }

        num = num * 10 + (*ptr - '0');
        // Early range check to avoid integer overflow
        if (num > 255) {
            return 0;
        }

        ptr++;
    }

    // Final octet checks after the loop ends
    if (dots != 3) {
        return 0;
    }
    if (ptr == start) {
        return 0;  // Empty last octet
    }
    if (start[0] == '0' && ptr - start > 1) {
        return 0;  // Leading zero in last octet
    }
    if (num < 0 || num > 255) {
        return 0;
    }

    return 1;
}


/* Return 1 is addr is a valid IP address, return 0 otherwise */
int is_valid_ip_v4(const char *addr) {
  struct sockaddr_in sockaddr;
  return inet_pton(AF_INET, addr, &(sockaddr.sin_addr)) ? 1 : 0;
}