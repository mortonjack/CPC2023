#include <iostream>
using namespace std;

unsigned int buy(unsigned int coins, unsigned int desserts) {
  // Step 1: Find highest cost dessert affordable
  if (!coins) return 1;
  unsigned int cost = 1;
  for (int i = 0; (cost << 1) <= coins; i++) {
    cost <<= 1;
    if (i+1 == desserts) return cost;
  }

  // Step 2: All combinations of desserts below this are affordable!
  unsigned int total = cost;

  // Step 3: Buy max-cost, add # affordable with remaining coins
  total += buy(coins-cost, desserts);

  return total;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unsigned int n, k;
    cin >> n >> k;
    cout << buy(n, k) << '\n';
  }
  return 0;
}