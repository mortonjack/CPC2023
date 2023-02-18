#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <set>
using namespace std;

bool bt(vector<int>& greedy, vector<int>& nums, set<int>& available, size_t i) {
    if (i == nums.size()) return true;
    for (auto num: available) {
        if (num == nums[i]) continue;
        greedy[i] = num;
        available.erase(available.find(num));
        if (bt(greedy, nums, available, i+1)) return true;
        available.insert(num);
        greedy[i] = -1;
    }
    return false;
}

vector<int> mystic(vector<int>& nums) {
    // Be greedy, backtrack when not working.
    // We can ensure a solution exists if no number appears in more than half of the cases
    set<int> available;
    for (auto& num: nums) available.insert(num);
    vector<int> greedy(nums.size(), -1);
    // This should always return true
    bt(greedy, nums, available, 0);
    return greedy;
}

int main() {
    int lines;
    cin >> lines;
    vector<vector<int>> cases(lines);
    for (auto& vec: cases) {
        int len;
        cin >> len;
        vec = vector<int> (len);
        for (int j = 0; j < len; j++) cin >> vec[j];
    }

    for (auto& input: cases) {
        vector<int> ans = mystic(input);
        for (auto& num: ans) cout << num << ' ';
        cout << '\n';
    }

    return 0;
}
