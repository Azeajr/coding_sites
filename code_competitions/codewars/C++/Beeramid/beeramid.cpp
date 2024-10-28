#include <iostream>

// Returns number of complete beeramid levels
int beeramid(int bonus, double price) {
  int beers = bonus / price;

  int count = 1;

  for (int i = 1; beers >= i * i; i++) {
    beers -= i * i;
    count++;
  }

  return count - 1;
}

// int main(int argc, char *argv[]) {
//   // std::cout << "Enter a bonus and a price: ";

//   // testing::InitGoogleTest(&argc, argv);
//   int bonus = std::stoi(argv[1]);
//   double price = std::stod(argv[2]);

//   // std::cin >> bonus >> price;

//   std::cout << "bonus: " << bonus << "\tprice: " << price << std::endl;

//   std::cout << beeramid(bonus, price) << std::endl;

//   return 0;

//   // return RUN_ALL_TESTS();
// }
