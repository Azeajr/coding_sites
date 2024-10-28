#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, m, k;
  std::cin >> n >> m >> k;

  std::unordered_map<std::string, std::pair<int, int>> destinations;

  std::string destination;
  int destinationCost;
  for (int i = 0; i < k; i++) {
    std::cin >> destination >> destinationCost;
    destinations[destination] = std::pair<int, int>(destinationCost, 0);
  }

  std::string customers[n];

  for (int i = 0; i < n; i++) {
    // std::getline(std::cin, customers[i]);
    std::cin >> customers[i];
    destinations[customers[i]].second++;
  }

  std::cout << n << m << k << std::endl;

  for (const auto &d : destinations) {
    std::cout << "Destination:[" << d.first << "] Cost:[" << d.second.first
              << "] Count:[" << d.second.second << "]" << std::endl;
  }

  for (std::string x : customers) {
    std::cout << x << std::endl;
  }

  int customersWindows[n];

  return 0;
}
