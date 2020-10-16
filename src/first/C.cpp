#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

vector<pair<int, int>> pad;

int dp[101][101];
int n, m;

bool is_pad(int x, int y) {
    for (const auto &p : pad) {
        if (x == p.first && y == p.second) {
            return true;
        }
    }
    return false;
}

ll DP(int x, int y) {
    int &r = dp[x][y];
    if (x < 0 || x > n || y < 0 || y > m) {
        return 0;
    }
    if (r != -1) {
        return r;
    }
    if (is_pad(x, y)) {
        r = 0;
    } else if (x == n && y == m) {
        r = 1;
    } else {
        r = 0;
        r += DP(x + 1, y);
        r %= 1000000007;
        r += DP(x, y + 1);
        r %= 1000000007;
    }
    return r;
}

int main(void) {
    cin >> m >> n;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = -1;
        }
    }
    int pad_len;
    cin >> pad_len;
    for (int i = 0; i < pad_len; i++) {
        pair<int, int> p;
        std::cin >> p.second >> p.first;
        pad.push_back(p);
    }
    ll res = DP(1, 1);
    std::cout << res;

    return 0;
}