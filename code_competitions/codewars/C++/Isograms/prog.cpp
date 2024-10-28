// An isogram is a word that has no repeating letters, consecutive or
// non-consecutive. Implement a function that determines whether a string that
// contains only letters is an isogram. Assume the empty string is an isogram.
// Ignore letter case.
#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_set>
#include <iostream>

bool is_isogram(std::string str) {
  std::transform(
      str.begin(), str.end(), str.begin(),
      [](unsigned char c) -> unsigned char { return std::tolower(c); });

  std::unordered_set<char> alpha;

  for( auto c : str){
    if(alpha.find(c) == alpha.end()){
      alpha.insert(c);
    }else{
      return false;
    }
  }

  return true;
}

int main(int argc, char const *argv[])
{
  std::cout << "Enter an string: ";

  std::string input;
  std::cin >> input;

  std::cout << is_isogram(input) << std::endl;

  return 0;
}
