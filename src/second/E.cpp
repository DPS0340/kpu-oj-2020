#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
int n, m;
int graph[301][301];

int temp[301][301];

bool solve(int gidx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == gidx || j == gidx) {
                temp[i][j] = INF;
            } else {
                temp[i][j] = graph[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][k] != INF && temp[k][j] != INF &&
                    temp[i][j] > temp[i][k] + temp[k][j]) {
                    temp[i][j] = temp[i][k] + temp[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != gidx && j != gidx && temp[i][j] == INF) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    vector<int> res;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        bool t = solve(i);
        if (t) {
            res.push_back(i + 1);
        }
    }
    cout << res.size() << '\n';
    for (const auto &e : res) {
        cout << e << '\n';
    }
}