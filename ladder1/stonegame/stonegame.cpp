#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int stoneGame(vector<int>& stones) {
    int smallest = 0, biggest = 0;
    for (int i = 1; i < (int)stones.size(); i++) {
        if (stones[i] < stones[smallest]) smallest = i;
        if (stones[i] > stones[biggest]) biggest = i;
    }

    // 4 cases: Both from left, both from right, or opposite ends
    int both_left = max(smallest, biggest)+1;
    int both_right = stones.size()-min(smallest, biggest);
    int smallest_left = smallest+1 + stones.size()-biggest;
    int biggest_left = biggest+1 + stones.size()-smallest;
    return min(min(both_left, both_right), min(smallest_left, biggest_left));
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
        cout << stoneGame(input) << '\n';
    }

    return 0;
}
