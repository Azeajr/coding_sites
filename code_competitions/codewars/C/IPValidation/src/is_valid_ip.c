#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_valid_ip(const char *addr) {

  regex_t reegex;

  int value = regcomp(&reegex,
                      "^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                      "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                      "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\."
                      "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)$",
                      REG_EXTENDED);
  if (value) {
    fprintf(stderr, "Could not compile regex\n");
    exit(1);
  }
  value = regexec(&reegex, addr, 0, NULL, 0);
  regfree(&reegex);

  return value == 0;
}
