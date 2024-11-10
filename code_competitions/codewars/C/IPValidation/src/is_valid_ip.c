#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_ip(const char *addr) {
    if (addr == NULL) {
        return false;
    }

    int num = 0;
    int dots = 0;
    const char *ptr = addr;
    const char *start = addr;

    while (*ptr) {
        if (*ptr == '.') {
            // Empty octet (consecutive dots or leading/trailing dot)
            if (ptr == start) {
                return false;
            }
            // Leading zero in octet (except for zero itself)
            if (start[0] == '0' && ptr - start > 1) {
                return false;
            }
            // Octet value out of range
            if (num < 0 || num > 255) {
                return false;
            }
            dots++;
            if (dots > 3) {
                return false;
            }
            num = 0;
            ptr++;
            start = ptr;
            continue;
        }

        if (!isdigit((unsigned char)*ptr)) {
            return false;
        }

        num = num * 10 + (*ptr - '0');
        // Early range check to avoid integer overflow
        if (num > 255) {
            return false;
        }

        ptr++;
    }

    // Final octet checks after the loop ends
    if (dots != 3) {
        return false;
    }
    if (ptr == start) {
        return false;  // Empty last octet
    }
    if (start[0] == '0' && ptr - start > 1) {
        return false;  // Leading zero in last octet
    }
    if (num < 0 || num > 255) {
        return false;
    }

    return true;
}
