#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int maxIncrease(vector<int>& nums) {
    int longest = 0;
    int curr = 0;
    int prev = 0;
    for (auto& num: nums) {
        if (num > prev) curr++;
        else curr = 1;
        prev = num;
        longest = max(curr, longest);
    }
    return longest;
}

int main() {
    int len;
    cin >> len;
    vector<int> vec(len);
    for (int i = 0; i < len; i++) cin >> vec[i];

    cout << maxIncrease(vec) << '\n';

    return 0;
}
