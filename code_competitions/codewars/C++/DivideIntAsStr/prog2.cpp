#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int subtract_strings(string *a, string *b) {
  int i = a->size() - 1, j = b->size() - 1;
  if (i < j || (i == j && (*a)[0] < (*b)[0])) {
    return 0;
  }

  while (i >= 0 && j >= 0) {
    if ((*a)[i] >= (*b)[j]) {
      (*a)[i] = (*a)[i] - (*b)[j] + '0';
    } else {
      (*a)[i] = 10 + (*a)[i] - (*b)[j] + '0';

      int k = 1;
      while (i - k >= 0) {
        if ((*a)[i - k] > '0') {
          (*a)[i - k]--;
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

  i = a->size();

  if ((*a)[0] == '0' && i > 1) {
    (*a).erase(0, 1);
  }
  return 1;
}

vector<string> divide_strings(string a, string b) {
  string quotient = "0";
  unsigned i = a.size(), j = b.size();
  if (i < j || (i == j && a[0] < b[0])) {
    return vector<string>{quotient, a};
  }

  while (subtract_strings(&a, &b)) {
    increment_string(&quotient);
  }

  return std::vector<std::string>{quotient, a};
}

int main(int argc, char const *argv[]) {

  srand(time(NULL));
  string a, b;
  if (argc == 3) {
    a = argv[1];
    b = argv[2];
  } else if (a.empty()) {
    for (int i = 0; i < rand() % 25 + 175; i++) {
      a += rand() % 10 + '0';
    }

    for (int i = 0; i < rand() % 50 + 125; i++) {
      b += rand() % 10 + '0';
    }
  }

  std::cout << a << "\n" << b << std::endl;

  for (auto x : divide_strings(a, b)) {
    std::cout << x << std::endl;
  }

  return 0;
}