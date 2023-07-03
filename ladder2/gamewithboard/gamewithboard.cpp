#include <iostream>
#include <array>
using namespace std;

bool game(array<int, 101>& state) {
  bool end = true;
  for (int i = 1; i < state.size(); i++) {
    for (int j = 2; j <= state[i]; j++) {
      end = false;
      state[i] -= j;
      state[i*j]++;
      bool cond = game(state);
      state[i*j]--;
      state[i] += j;
      if (!cond) return true;
    }
  }
  return end;
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int n;
    cin >> n;
    array<int, 101> state = {0};
    state[1] = n;
    cout << (game(state) ? "Alice" : "Bob") << endl;
  }
  return 0;
}