#include <iostream>
#include <string>
#include <queue>
using namespace std;

class block {
public:
  block(int i, int t): index(i), time(t) {}
  int index;
  int time;
};

void query(string& s1, string& s2, int t, int queries) {
  // Count differences
  int differences = 0;
  for (int i = 0; i < s1.length(); i++) differences += s1[i] != s2[i];

  // Conduct queries
  queue<block> blocked;
  for (int q = 1; q <= queries; q++) {
    // Unblock
    while (!blocked.empty()) {
      block b = blocked.front();
      if (b.time > q) break;
      blocked.pop();
      differences += s1[b.index] != s2[b.index];
    }
    int type;
    cin >> type;
    if (type == 1) {
      // Block
      int pos;
      cin >> pos;
      --pos;
      differences -= s1[pos] != s2[pos];
      blocked.emplace(pos, q+t);
    } else if (type == 2) {
      // Swap
      int str, pos;
      cin >> str >> pos;
      char& c1 = (str == 1) ? s1[pos-1] : s2[pos-1];
      char& c1_comp = (str != 1) ? s1[pos-1] : s2[pos-1]; 
      cin >> str >> pos;
      char& c2 = (str == 1) ? s1[pos-1] : s2[pos-1];
      char& c2_comp = (str != 1) ? s1[pos-1] : s2[pos-1]; 
      differences -= c1 != c1_comp;
      differences -= c2 != c2_comp;
      swap(c1, c2);
      differences += c1 != c1_comp;
      differences += c2 != c2_comp;
    } else {
      // Equal?
      cout << (differences ? "NO" : "YES") << '\n';
    }
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int t, q;
    cin >> t >> q;
    query(s1, s2, t, q);
  }
  return 0;
}