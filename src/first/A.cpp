#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        next_permutation(v.begin(), v.end());
        for (int j = 0; j < n; j++) {
            cout << v[j];
            // if (j != n - 1) {
            cout << ' ';
            // }
        }
        cout << '\n';
    }
}