#include <iostream>
#include <string>
#include <vector>

int compare_string(std::string *a, std::string *b) {
  if (a->size() > b->size()) {
    return 1;
  } else if (a->size() < b->size()) {
    return 0;
  }

  for (int i = 0; i < (int)a->size(); i++) {
    if ((*a)[i] < (*b)[i])
      return 0;
  }
  return 1;
}

int subtract_strings(std::string *a, std::string *b) {
  int i = a->size() - 1, j = b->size() - 1;

  if (compare_string(a, b)) {
    while (i >= 0 && j >= 0) {
      if ((*a)[i] >= (*b)[j]) {
        (*a)[i] = (*a)[i] - (*b)[j] + '0';
      } else {
        int k = 1;
        while (i - k >= 0) {
          if ((*a)[i - k] != '0') {
            (*a)[i - k]--;
            (*a)[i] = 10 + (*a)[i] - (*b)[j] + '0';
            break;
          } else {
            (*a)[i - k] = '9';
            k++;
          }
        }
      }
      i--;
      j--;
    }

    i = -1;
    while (i < (int)a->size()-1) {
      if ((*a)[i + 1] != '0') {
        break;
      }

      i++;
    }

    a->erase(0, a->find_first_not_of('0'));

    if(a->size() == 0){
      (*a).append("0\0");
    }
    return 1;
  } else {
    return 0;
  }
}

void increment_string(std::string *a) {
  for (int i = (*a).size() - 1; i >= 0; i--) {
    if ((*a)[i] < '9') {
      (*a)[i]++;
      break;
    } else {
      (*a)[i] = '0';
    }
    if (i == 0) {
      (*a).insert(0, 1, '1');
      break;
    }
  }
}

std::vector<std::string> divide_strings(std::string a, std::string b) {
  std::string quotient = "0";

  while (subtract_strings(&a, &b)) {
    increment_string(&quotient);
  }

  return std::vector<std::string>{quotient, a};
}

int main(int argc, char const *argv[]) {
  std::string dividend = argv[1];
  std::string divisor = argv[2];
  for (auto x : divide_strings(argv[1], argv[2])) {
    std::cout << x << std::endl;
  }

  // std::string temp1 = argv[1];
  // std::string temp2 = argv[2];

  // std::cout << temp1 << "\t" << temp2 << std::endl;
  // subtract_strings(&temp1, &temp2);

  // std::cout << temp1 << "\t" << temp2 << std::endl;

  // std::cout << temp1 << std::endl;std::cout << temp1 << std::endl;
  // increment_string(&temp1);
  // s
  // increment_string(&temp1);
  // std::cout << temp1 << std::endl;

  return 0;
}