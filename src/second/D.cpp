#include <bits/stdc++.h>

// 주의! PA 코드

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    int min_dist = 987654321;
    for (int i = 0; i < n - 1; i++) {
        if (vp[i].second ^ vp[i + 1].second) {
            min_dist = min(min_dist, vp[i + 1].first - vp[i].first - 1);
        }
    }
    bool visited = false;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!vp[i].second) {
            continue;
        }
        if (vp[i + 1].first - vp[i].first <= min_dist) {
            if (!visited) {
                cnt++;
            }
            visited = true;
        } else {
            visited = true;
            cnt++;
        }
    }
    cout << cnt;
}