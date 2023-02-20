#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/* input: ())(())(())(
 * valid: () (())(())
 * before 011112333444
 * after  544432221000
 * depth  100121012101
 *
 * input: ())(()())((()
 * valid: () (()())  ()
 * before 0111122344445
 * after  5444322111110
 * depth  1001212100010
 */

int longestSubsequence(vector<int>& open, vector<int>& close, vector<int>& rightbound,
        vector<int>& depth, vector<int>& left, int l, int r, int total) {
    int cross = left[l];
    while (cross != -1 && rightbound[cross] <= r) cross = left[cross];
    return total - (l == 0 ? 0 : open[l-1]) - (close.back() - close[r]) + (cross == -1 ? 0 : depth[cross]);
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> open(n, -1);
    vector<int> close(n, -1);
    vector<int> depth(n, 0);
    vector<int> left(n, -1);
    int total = 0;
    stack<int> unclosed;
    for (int i = 0; i < n; i++) {
        if (!unclosed.empty()) left[i] = unclosed.top();
        if (s[i] == '(') {
            unclosed.push(i);
        } else if (!unclosed.empty()) {
            close[i] = unclosed.top(); unclosed.pop();
            open[close[i]] = i;
            total++;
        }
    }
    int curr_depth = open[0] != -1;
    vector<int> valid_open(n, 0);
    valid_open[0] = curr_depth;
    depth[0] = curr_depth;
    vector<int> valid_close(n, 0);
    for (int i = 1; i < n; i++) {
        if (open[left[i]] == -1) left[i] = -1;
        valid_open[i] = valid_open[i-1];
        valid_close[i] = valid_close[i-1];
        if (close[i] != -1) {
            curr_depth--;
            valid_close[i]++;
        }
        if (open[i] != -1) {
            valid_open[i]++;
            curr_depth++;
        }
        depth[i] = curr_depth;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << 2*longestSubsequence(valid_open, valid_close, open, depth, left, l-1, r-1, total) << '\n';
    }
    return 0;
}
