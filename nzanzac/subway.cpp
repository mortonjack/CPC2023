#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

#define DIST double

DIST distance(int x1, int y1, int x2, int y2) {
    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
}

DIST train_time(int x1, int y1, int x2, int y2) {
    return distance(x1, y1, x2, y2) / ((40.0*1000.0) / 60.0);
}

DIST walk_time(int x1, int y1, int x2, int y2) {
    return distance(x1, y1, x2, y2) / ((10.0*1000.0) / 60.0);
}

int main() {
    int x_h, y_h, x_u, y_u, n;
    cin >> x_h >> y_h >> x_u >> y_u >> n;
    vector<vector<pair<int, int>>> lines;
    int x, y, total_pos = 2;
    vector<pair<int, int>> nodes;
    nodes.emplace_back(x_h, y_h);
    nodes.emplace_back(x_u, y_u);
    while (n--) {
        lines.push_back({});
        cin >> x >> y;
        while (x != -1) {
            total_pos++;
            lines.back().push_back({x, y});
            nodes.emplace_back(x, y);
            cin >> x >> y;
        }
    }

    // Set up adjacency matrix
    vector<vector<DIST>> adj(total_pos, vector<DIST>(total_pos, 0.0));
    int k = 2;
    for (auto line: lines) {
        for (int j = 1; j < (int)line.size(); j++) {
            adj[k+j][k+j-1] = train_time(line[j].first, line[j].second, line[j-1].first, line[j-1].second);
            adj[k+j-1][k+j] = adj[k+j][k+j-1];
        }
        k += line.size();
    }

/*    // testing
    for (auto i: adj) {
        for (auto j: i) {
            cout << (int)j << '\t';
        }
        cout << endl;
    }
*/

    // Figure out walking distances
    for (int i = 0; i < (int)nodes.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            DIST walk = walk_time(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second);
            DIST best;
            if (adj[i][j] == 0.0) {
                best = walk;
            } else {
                best = min(walk, adj[i][j]);
            }
            adj[i][j] = best;
            adj[j][i] = best;
        }
    }

/*    // testing
    cout << endl;
    for (auto i: adj) {
        for (auto j: i) {
            cout << (int)j << '\t';
        }
        cout << endl;
    }
*/

    // DJIKSTRA
    priority_queue<pair<DIST, int>, vector<pair<DIST, int>>, greater<pair<DIST, int>>> q;
    vector<bool> visited(nodes.size(), false);
    q.emplace(0, 0);
    while (!q.empty()) {
        auto top = q.top(); q.pop();
        DIST time = top.first;
        int node = top.second;
        if (visited[node]) continue;
        visited[node] = true;
        if (node == 1) {
            int time_d = time, time_u = time_d+1;
            cout << (time-(DIST)time_d < (DIST)time_u-time ? time_d : time_u) << endl;
            return 0;
        }

        // look at adjacent 
        for (int i = 0; i < (int)nodes.size(); ++i) if (i != node && !visited[i]) {
            q.emplace(time + adj[node][i], i);
        }
    }

    return 1;
}
