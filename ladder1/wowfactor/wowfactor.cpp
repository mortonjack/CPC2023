#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <set>
using namespace std;

long long wowFactor(string& s) {
    if (s.length() < 5) return 0;
    long long right = 0, left = 0, wow = 0;

    for (size_t i = s.length()-2; i >= 1; i--) {
        if (s[i] == 'v' && s[i+1] == 'v') right++;
    }

    for (size_t i = 1; i < s.length()-1; i++) {
        if (s[i] == 'v') {
            // Add w from left, remove from right
            if (s[i-1] == 'v') left++;
            if (s[i+1] == 'v') right--;
        } else wow += left*right;
    }
    

    return wow;
}

int main() {
    string s;
    cin >> s;
    cout << wowFactor(s) << '\n';
    return 0;
}
