#include <iostream>
#include <vector>
#include <set>
using namespace std;

void answerQueries(vector<int>& arr, vector<vector<int>>& queries) {
    set<int> indices;
    for (int i = 0; i < (int)arr.size(); i++) indices.insert(i);

    for (auto& query: queries) {
        if (query[0] == 1) {
            // Update in range
            auto it = indices.lower_bound(query[1]);
            while (it != indices.end() && *it <= query[2]) {
                int sum = 0;
                int i = *it;
                while (arr[i] != 0) {
                    sum += arr[i] % 10;
                    arr[i] /= 10;
                }
                arr[i] = sum;
                it++;
                if (sum < 10) indices.erase(i);
            }
        } else {
            cout << arr[query[1]] << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        vector<vector<int>> queries(q, vector<int>(2));
        for (int j = 0; j < n; j++) cin >> arr[j];
        for (int j = 0; j < q; j++) {
            cin >> queries[j][0] >> queries[j][1];
            queries[j][1]--;
            if (queries[j][0] == 1) {
                queries[j].push_back(-1);
                cin >> queries[j][2];
                queries[j][2]--;
            }
        }
        answerQueries(arr, queries);
    }

    return 0;
}
