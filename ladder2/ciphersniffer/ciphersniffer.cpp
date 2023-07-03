#include <iostream>
#include <string>
using namespace std;

string decrypt(string& s) {
  string res = "";
  char prev = '\0';
  for (char c: s) {
    if (prev == '\0') {
      res += c;
      prev = c;
    } else if (prev == c) {
      prev = '\0';
    }
  }
  return res;
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int len;
    cin >> len;
    string s;
    cin >> s;
    cout << decrypt(s) << '\n';
  }
  return 0;
}