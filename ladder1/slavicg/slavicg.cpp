#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* 
 * No reason to go over the same edge twice
 * DFS to EVERY NODE from B, and add the XOR value we find to a set
 * DFS to EVERY NODE from A, and check if its XOR value is in the set
 * If we get to node B, we don't check, we backtrack
 */

bool dfs(vector<vector<pair<int, int>>>& adj, unordered_set<int>& reachable, int node, int b, bool a, int x, int parent) {
    // Insert x into set OR look for x in set
    if (a) {
        if (reachable.find(x) != reachable.end()) return true;
    } else if (node != b) {
        reachable.insert(x);
    }

    // Look at all neighbours
    for (auto& neighbour: adj[node]) {
        int u = neighbour.first, w = neighbour.second;
        if (u == parent) continue;
        if (a && u == b) continue;
        if (dfs(adj, reachable, u, b, a, x ^ w, node)) return true;
    }
    
    return false;
}

bool canReach(vector<vector<pair<int, int>>>& adj, int a, int b) {
    unordered_set<int> reachable;
    dfs(adj, reachable, b, b, false, 0, -1);
    return dfs(adj, reachable, a, b, true, 0, -1);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<pair<int, int>>> adj(n);
        for (int j = 1; j < n; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u-1].push_back({v-1, w});
            adj[v-1].push_back({u-1, w});
        }
        cout << (canReach(adj, a-1, b-1) ? "YES" : "NO") << '\n';
    }
    return 0;
}
