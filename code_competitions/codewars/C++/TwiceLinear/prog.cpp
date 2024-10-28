#include <cmath>
#include <iostream>
#include <vector>
#include <set>

class DoubleLinear {
public:
  static int dblLinear(int n) {
    std::set<unsigned> dblSet;
    dblSet.insert(1);
    // std::vector<unsigned> temp;

    for (int j = 0; j <= std::ceil(std::log2(n))+1; j++) {
      std::vector<unsigned> temp(dblSet.begin(), dblSet.end());

      for (long unsigned int i = 0; i < temp.size(); i++) {
        dblSet.insert(2 * temp[i] + 1);
        dblSet.insert(3 * temp[i] + 1);
      }
    }

    return *std::next(dblSet.begin(), n);
  }
};

int main(int argc, char const *argv[]) {
  // std::cout << DoubleLinear::dblLinear(10) << ":" << 22 << std::endl;
  // std::cout << DoubleLinear::dblLinear(20) << ":" << 57 << std::endl;
  // std::cout << DoubleLinear::dblLinear(30) << ":" << 91 << std::endl;
  // std::cout << DoubleLinear::dblLinear(50) << ":" << 175 << std::endl;
  std::cout << DoubleLinear::dblLinear(1200000) << ":" << 7202134 << std::endl;


  return 0;
}
