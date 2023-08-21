#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
      int rownum = r*2;
      if (n == 4) rownum = r<2 ? (r*2)+1 : (r-2)*2;
      else if (rownum >= n && n % 2) rownum %= n;
      else if (rownum >= n) ++rownum %= n;
      rownum *= m;
      for (int c = 1; c <= m; c++) {
        cout << rownum + c << '\t';
      }
      cout << '\n';
    }
    cout << endl;
  }
  return 0;
}