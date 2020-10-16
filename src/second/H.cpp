#include <bits/stdc++.h>
using namespace std;

int n, m;
int Map[1001][1001];

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        int sum = 0;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                sum += Map[i][j];
            }
        }
        cout << sum << '\n';
    }
}