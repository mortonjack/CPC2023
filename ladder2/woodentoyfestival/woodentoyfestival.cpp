#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int divisor(vector<int>& vec, int cutoff) {
  int lo = cutoff+1, hi = vec.size()-2;
  int low = vec[lo], high = vec.back();

  while (lo+1 < hi) {
    int half = lo + (hi-lo)/2;
    if (vec[half]-low == high-vec[half+1]) return half;
    if (vec[half]-low < high-vec[half+1]) lo = half;
    else hi = half;
  }
  if (lo == hi) return lo;
  if (max(vec[lo]-low, high-vec[lo+1]) < max(vec[lo+1]-low, high-vec[lo+2])) {
    return lo;
  } else return lo+1;
}

int lowestTime(vector<int>& vec) {
  if (vec.size() <= 3) return 0;
  int difference = vec.back()-vec.front();
  for (int i = 0; i < vec.size()-2; i++) {
    int l = vec[i]-vec.front();
    int j = divisor(vec, i);
    int m = vec[j]-vec[i+1];
    int r = vec.back()-vec[j+1];
    difference = min(difference, max(l/2 + l%2, max(m/2 + m%2, r/2 + r%2)));
  }
  return difference;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, num;
    cin >> n;
    vector<int> vec;
    set<int> input;
    for (int j = 0; j < n; j++) {
      cin >> num;
      input.insert(num);
    }
    for (auto num: input) vec.push_back(num);
    cout << lowestTime(vec) << '\n';
  }
  return 0;
}