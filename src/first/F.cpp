#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int m, n;
vector<string> _map;

void bfs() {
    queue<pair<int, int>> q;
    pair<int, int> p;
    int mx;
    int my;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_map[i][j] == 'M') {
                p.first = i;
                p.second = j;
                mx = i;
                my = j;
            }
        }
    }
    q.push(p);
    vector<vector<bool>> visited(n);
    for (int i = 0; i < n; i++) {
        visited[i].resize(m);
    }
    map<pair<int, int>, pair<int, int>> path;
    vector<pair<int, int>> path_;
    while (!q.empty()) {
        auto &p = q.front();
        int x = p.first;
        int y = p.second;
        visited[x][y] = 1;
        q.pop();
        if (_map[x][y] == 'D') {
            auto p1 = make_pair(x, y);
            while (p1.first != mx || p1.second != my) {
                p1 = path[make_pair(p1.first, p1.second)];
                path_.push_back(p1);
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (_map[i][j] == '.' &&
                        find(path_.begin(), path_.end(), make_pair(i, j)) !=
                            path_.end()) {
                        cout << 'x';
                    } else {
                        cout << _map[i][j];
                    }
                }
                if (i != n - 1) {
                    cout << '\n';
                }
            }
            exit(0);
        }
        pair<int, int> p1(x - 1, y);
        pair<int, int> p2(x + 1, y);
        pair<int, int> p3(x, y - 1);
        pair<int, int> p4(x, y + 1);
        pair<int, int> p5(n - 1, y);
        pair<int, int> p6(x, m - 1);
        pair<int, int> p7(0, y);
        pair<int, int> p8(x, 0);
        pair<int, int> p0(x, y);

        if (x - 1 >= 0 && _map[x - 1][y] != '#' &&
            !visited[p1.first][p1.second]) {
            visited[p1.first][p1.second] = 1;
            path[p1] = p0;
            q.push(p1);
        }
        if (y - 1 >= 0 && _map[x][y - 1] != '#' &&
            !visited[p3.first][p3.second]) {
            visited[p3.first][p3.second] = 1;
            path[p3] = p0;
            q.push(p3);
        }
        if (x + 1 < n && _map[x + 1][y] != '#' &&
            !visited[p2.first][p2.second]) {
            visited[p2.first][p2.second] = 1;
            path[p2] = p0;
            q.push(p2);
        }
        if (y + 1 < m && _map[x][y + 1] != '#' &&
            !visited[p4.first][p4.second]) {
            visited[p4.first][p4.second] = 1;
            path[p4] = p0;
            q.push(p4);
        }
        if (x == 0 && _map[n - 1][y] != '#' && !visited[p5.first][p5.second]) {
            visited[p5.first][p5.second] = 1;
            path[p5] = p0;
            q.push(p5);
        }
        if (x == n - 1 && _map[0][y] != '#' && !visited[p7.first][p7.second]) {
            visited[p7.first][p7.second] = 1;
            path[p7] = p0;
            q.push(p7);
        }
        if (y == 0 && _map[x][m - 1] != '#' && !visited[p6.first][p6.second]) {
            visited[p6.first][p6.second] = 1;
            path[p6] = p0;
            q.push(p6);
        }
        if (y == m - 1 && _map[x][0] != '#' && !visited[p8.first][p8.second]) {
            visited[p8.first][p8.second] = 1;
            path[p8] = p0;
            q.push(p8);
        }
    }
    cout << "NO";
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        _map.push_back(s);
    }

    bfs();
}