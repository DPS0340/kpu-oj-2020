#include <bits/stdc++.h>

using namespace std;

char Map[1002][1002];
int x, y;
int lim;
int max_storm;

int bfs() {
    int res = 0;
    int cnt = 0;
    std::queue<pair<int, int>> q;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (Map[i][j] == '.') {
                int size = 0;
                q.push(make_pair(i, j));
                cnt++;
                while (!q.empty()) {
                    int xP = q.front().first;
                    int yP = q.front().second;
                    q.pop();
                    if (Map[xP][yP] != '.') {
                        continue;
                    }
                    Map[xP][yP] = ',';
                    size++;
                    int possX[] = {xP - 1, xP,     xP,     xP + 1,
                                   xP + 1, xP + 1, xP - 1, xP - 1};
                    int possY[] = {yP,     yP - 1, yP + 1, yP,
                                   yP + 1, yP - 1, yP + 1, yP - 1};
                    for (int k = 0; k < 8; k++) {
                        if (0 <= possX[k] && possX[k] < x && 0 <= possY[k] &&
                            possY[k] < y && Map[possX[k]][possY[k]] == '.') {
                            q.push(make_pair(possX[k], possY[k]));
                        }
                    }
                }
                if (size > lim) {
                    res++;
                    max_storm = max(max_storm, size);
                }
            }
        }
    }
    return res;
}

int main(void) {
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < y; j++) {
            Map[i][j] = s[j];
        }
    }
    cin >> lim;
    int res = bfs();
    cout << res << ' ' << max_storm;
}