#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool canMake(string& s, string& t) {
    bool del = false;
    int j = t.length()-1;
    for (int i = s.length()-1; i >= 0 && j >= 0; i--) {
        if (del) del = false;
        else if (s[i] == t[j]) j--;
        else del = true;
    }
    return j < 0;
}

int main() {
    int cases;
    cin >> cases;
    string s, t;
    for (int i = 0; i < cases; i++) {
        cin >> s >> t;
        cout << (canMake(s, t) ? "YES" : "NO") << '\n';
    }

    return 0;
}
