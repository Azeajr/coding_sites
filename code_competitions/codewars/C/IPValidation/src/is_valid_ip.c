#include <stdio.h>
#include <regex.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_valid_ip(const char *addr) {
    regex_t regex;
    const char *pattern = "^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                          "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                          "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                          "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)$";

    // Compile the regular expression
    int compile_err = regcomp(&regex, pattern, REG_EXTENDED);
    if (compile_err != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    // Execute the regular expression
    int exec_err = regexec(&regex, addr, 0, NULL, 0);
    regfree(&regex); // Free the compiled regular expression

    return exec_err == 0;
}
