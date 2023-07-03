#include <iostream>
using namespace std;

int trips(int n, int min_days, int max_temp) {
  int temp, total = 0, curr_len = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp <= max_temp) curr_len++;
    else curr_len = 0;
    if (curr_len >= min_days) {
      total += curr_len - min_days + 1;
    }
  }
  return total;
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; ++i) {
    int n, k, q;
    cin >> n >> k >> q;
    cout << trips(n, k, q) << '\n';
  }
}