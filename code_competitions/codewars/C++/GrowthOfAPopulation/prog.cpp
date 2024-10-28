#include <cmath>
#include <iostream>

class Arge {
public:
  static int nbYear(int p0, double percent, int aug, int p) {
    percent = (percent / 100.0) + 1.0;

    double x;

    if (percent == 1) {
      x = (p - p0) / aug;
    } else {
      x = p + (aug / (percent - 1));
      x /= p0 + (aug / (percent - 1));
      x = log(x);
      x /= log(percent);
      x = ceil(x);
    }

    if ((int)(p0 * pow(percent, x) +
              (aug / (percent - 1)) * (pow(percent, x) - 1)) == p) {
      return x + 1;
    }

    return x;
  }
};

int main(int argc, char const *argv[]) {
  std::cout << Arge::nbYear(1500, 5, 100, 5000) << -15 << std::endl;
  std::cout << Arge::nbYear(1500000, 2.5, 10000, 2000000) << -10 << std::endl;
  std::cout << Arge::nbYear(1500000, 0.25, 1000, 2000000) << -94 << std::endl;
  std::cout << Arge::nbYear(1500000, 0.25, -1000, 2000000) << -151 << std::endl;
  std::cout << Arge::nbYear(1500000, 0, 10000, 2000000) << -50 << std::endl;
  std::cout << Arge::nbYear(1500000, 5, 0, 2000000) << -6 << std::endl;
  std::cout << Arge::nbYear(1000, 2, 50, 1214) << -4 << std::endl;

  return 0;
}
