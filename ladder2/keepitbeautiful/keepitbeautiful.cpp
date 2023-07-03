#include <iostream>
#include <vector>
#include <string>
using namespace std;

string query(int queries) {
  int num;
  string res = "";
  bool wrapped = false;
  vector<int> arr;
  for (int i = 0; i < queries; i++) {
    cin >> num;
    if (arr.size() < 1) {
      arr.push_back(num);
      res += '1';
    } else if (!wrapped && num >= arr.back()) {
      arr.push_back(num);
      res += '1';
    } else if (!wrapped && num <= arr.front()) {
      wrapped = true;
      arr.push_back(num);
      res += '1';
    } else if (num >= arr.back() && num <= arr.front()) {
      arr.push_back(num);
      res += '1';
    } else {
      res += '0';
    }
  }
  return res;
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int queries;
    cin >> queries;
    cout << query(queries) << '\n';
  }
}