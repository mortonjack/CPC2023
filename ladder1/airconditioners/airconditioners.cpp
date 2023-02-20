#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void bestTemp(vector<int>& temps) {
    int n = temps.size();
    vector<int> left(temps.size(), INT_MAX-n);
    left.back() = temps.back();
    for (int i = n-2; i >= 0; i--) {
        left[i] = min(temps[i], left[i+1]+1);
    }
    for (int i = 1; i < n; i++) {
        temps[i] = min(temps[i], temps[i-1]+1);
    }
    for (int i = 0; i < n; i++) temps[i] = min(temps[i], left[i]);
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> temps(n, INT_MAX-n);
        vector<int> pos(k);
        for (auto& num: pos) cin >> num;
        for (auto& j: pos) {
            int num;
            cin >> num;
            temps[j-1] = num;
        }
        bestTemp(temps);
        for (auto& temp: temps) cout << temp << ' ';
        cout << '\n';
    }

    return 0;
}
