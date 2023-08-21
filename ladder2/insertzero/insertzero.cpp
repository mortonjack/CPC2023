#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> order(vector<int>& vec) {
  int pos = 0;
  vector<int> res;
  for (auto num: vec) {
    if (num == 0) {
      res.push_back(pos);
      while (pos) {
        res.push_back(0);
        --pos;
      }
    } else {
      ++pos;
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> vec;
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      vec.push_back(num);
    }
    if (vec.back() == 1) cout << "NO\n";
    else {
      cout << "YES\n";
      vector<int> res = order(vec);
      reverse(res.begin(), res.end());
      for (auto num: res) cout << num << ' ';
      cout << '\n';
    }
  }
  return 0;
}