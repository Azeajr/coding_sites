#include <cmath>
#include <iostream>
#include <string>

long countDivisors(const long &n) {
  // your calculations should go here
  long count = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if(i*j <= n){
        count++;
      }
    }
  }

    return count;
}

long countDivisors2(const long &n) {
  // your calculations should go here
  long target = sqrt(n);
  long count = 0;
  for (int i = 1; i <= target; i++) {
    count += 2 * (n / i + (1 - i)) - 1;
  }

  return count;
}

int main(int argc, char const *argv[]) {
  long input = std::stol(argv[1]);
  // std::cout << "Enter an natural number: ";
  // std::cin >> input;

  std::cout << countDivisors(input) << std::endl;
  std::cout << countDivisors2(input) << std::endl;

  return 0;
}
