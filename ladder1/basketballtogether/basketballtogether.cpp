#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <set>
using namespace std;

int maxWins(vector<int>& players, int d) {
    sort(players.begin(), players.end());
    int i = 0, j = players.size()-1; 
    int wins = 0;
    while (i <= j) {
        int score = players[j];
        i += d/score;
        if (i <= j) wins++;
        j--;
    }
    return wins;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> players(n);
    for (auto& num: players) {
        cin >> num;
    }

    cout << maxWins(players, d) << '\n';

    return 0;
}
