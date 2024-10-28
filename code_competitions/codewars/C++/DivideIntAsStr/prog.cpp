// #include <algorith>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>


std::string multiplyStringsByDigit(std::string a, int b) {
  if (b < 0 || b > 9)
    return nullptr;
  std::string product = "";
  int interimProduct;
  int carry = 0;

  for (int digitA = a.length() - 1; digitA >= 0; digitA--) {
    interimProduct = b * (a[digitA] - '0') + carry;
    carry = interimProduct / 10;
    interimProduct %= 10;

    product.insert(0, std::to_string(interimProduct));
  }

  if (carry > 0) {
    product.insert(0, std::to_string(carry));
  }

  return product;
}

int integerStringsCompare(std::string *a, std::string *b) {
  if ((*a).length() > (*b).length()) {
    return 1;
  } else if ((*a).length() < (*b).length()) {
    return -1;
  } else {
    for (int i = 0; i < (*a).length(); i++) {
      if ((*a)[i] > (*b)[i]) {
        return 1;
      } else if ((*a)[i] < (*b)[i]) {
        return -1;
      }
    }
    return 0;
  }
}

int largerIntegerFinder(std::string smaller, std::string larger, int index) {

  return 0;
}

std::vector<std::string> divide_strings(std::string *a, std::string *b) {
  std::string quotient = "0";
  std::string remainder = "0";

  int comp = integerStringsCompare(a, b);
  if (comp == -1) {
    return std::vector<std::string>{quotient, *a};
  } else if (comp == 0) {
    return std::vector<std::string>{"1", remainder};
  }

  int start = 0;
  for (int i = start; i < start + (*b).length() - 1; i++) {
  }

  return std::vector<std::string>{quotient, remainder};
}

int main(int argc, char const *argv[]) {
  std::string first = "1234";
  std::string second = "12";

  for (auto x : divide_strings(&first, &second)) {
    std::cout << x << std::endl;
  }

  std::string str = "TheBigStr";
  std::string_view p1 = std::string_view(str.data() + 3, 3);

  std::cout << p1;

  return 0;
}