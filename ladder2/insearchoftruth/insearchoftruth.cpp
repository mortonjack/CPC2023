#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

#define MAX_QUERIES 2023

int main() {
  int queries = 0, x, max_num, offset = 0;
  unordered_map<int, int> num_offsets;
  cin >> x;
  num_offsets[x] = 0;
  max_num = x;
  // Search for cycle
  while (queries < MAX_QUERIES) {
    cout << "+ " << x << endl;
    ++queries;
    offset += x;
    cin >> x;
    max_num = max(max_num, x);
    if (num_offsets.count(x)) {
      // Cycle detected
      int cycle = offset - num_offsets[x];
      // Look for factors of cycle greater than max_num
      for (int i = max_num; i <= cycle && queries < MAX_QUERIES; i++) 
      if (cycle % i == 0) {
        int y;
        ++queries;
        cout << "+ " << i << endl;
        cin >> y;
        if (y == x) {
          cout << "! " << i << endl;
          return 0;
        }
        x = y;
      }
      cout << "! " << cycle << endl;
      return 0;
    } else {
      num_offsets[x] = offset;
    }
  }
  // Output max number seen (no cycle found, take a guess)
  cout << "! " << max_num << endl;
  return 0;
}