
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  std::set<char> s = {'c', 'a', 'a', 'a', 'b', 'c', 'd', 'e'};

  std::vector<char> v(s.begin(), s.end());

  for (char const &c : v) {
    std::cout << c << ' ';
  }

  return 0;
}