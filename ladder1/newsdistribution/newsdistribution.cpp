#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <set>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent = vector(n+1, -1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        size = vector(n+1, 1);
    }

    // Find root
    int root(int n) {
        if (parent[n] == n) return n;
        return parent[n] = root(parent[n]);
    }

    // Return size of set
    int get_size(int n) {
        return size[root(n)];
    }

    // Merge two friends
    void merge(int a, int b) {
        int root_a = root(a), root_b = root(b);
        if (root_a == root_b) return;
        if (size[root_a] > size[root_b]) {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        } else {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
    }
};

vector<int> distribution(int n, vector<vector<int>> groups) {
    // Form DSU (Union-Find)
    DSU dsu(n);
    for (auto& group: groups) {
        for (auto& friendo: group) dsu.merge(group[0], friendo);
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) res[i] = dsu.get_size(i+1);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> groups;
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        vector<int> group;
        for (int i = 0; i < len; i++) {
            int mem;
            cin >> mem;
            group.push_back(mem);
        }
        if (group.size() > 0) groups.push_back(group);
    }
    
    vector<int> res = distribution(n, groups);
    for (auto& num: res) cout << num << ' ';
    cout << '\n';

    return 0;
}
