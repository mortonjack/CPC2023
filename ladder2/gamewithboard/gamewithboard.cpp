#include <iostream>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int n;
    cin >> n;
    cout << (n > 4 ? "Alice" : "Bob") << '\n';
  }
  return 0;
}