#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int m, t, s, n;
vector<vector<pair<int, int>>> v;

int dfs(vector<pair<int, int>> &visited, int start, int token, int time) {
    const auto &next = v[start][token];
    pair<int, int> p{start, token};
    if (visited.size() > 1 &&
        find(visited.begin(), visited.end(), p) != visited.end()) {
        auto start = find(visited.begin(), visited.end(), p);
        // cycle 생김
        int k = start - visited.begin();
        int idx = k + ((n - 1 - k) % (visited.size() - k));
        return visited[idx].first + 1;
    }
    visited.push_back(p);
    return dfs(visited, next.second, next.first, time + 1);
}

int main(void) {
    cin >> m >> t >> s >> n;
    s--;
    for (int i = 0; i < m; i++) {
        vector<pair<int, int>> vec;
        v.push_back(vec);
        for (int j = 0; j < t; j++) {
            int k, next;
            cin >> k >> next;
            k--;
            next--;
            pair<int, int> p1(k, next);
            v[i].push_back(p1);
        }
    }
    vector<pair<int, int>> _vec;
    int res = dfs(_vec, s, 0, 1);
    cout << res;
    return 0;
}