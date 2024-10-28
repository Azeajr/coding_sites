#include <iostream>
#include <string>

int string_to_number(const std::string &s) {
  return std::stoi(s);
}

int main(int argc, char const *argv[]) {
  std::cout << string_to_number("-124") << std::endl;
  return 0;
}
