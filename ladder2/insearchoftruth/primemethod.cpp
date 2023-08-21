#include <iostream>
#include <array>
using namespace std;

#define MAX_QUERIES 2023

constexpr array<int, 78498> genPrimes() {
  array<int, 78498> primes = {0};
  primes[0] = 2;
  int i = 0;
  for (int num = 3; num < 1000000; ++num) {
    bool isPrime = true;
    for (int j = 0; j <= i; j++) if (num % primes[j] == 0) {
      isPrime = false;
      break;
    };
    if (isPrime) primes[++i] = num;
  }
  return primes;
}

int main() {
  genPrimes();
  return 0;
}