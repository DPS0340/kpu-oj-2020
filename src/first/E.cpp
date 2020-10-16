#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<int> cost;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            c++;
        } else {
            cost.push_back(c);
            c = 0;
        }
    }
    if (c != 0) {
        cost.push_back(c);
    }
    int res;
    if (cost.size() == 1) {
        res = cost[0] - 1;
    } else {
        int l1 = 0;
        int l2 = 0;
        for (int i = 0, size = cost.size(); i < size; i++) {
            if (i == 0 || i == size - 1) {

            } else {
                cost[i] += cost[i] % 2;
                cost[i] /= 2;
            }
            if (cost[i] >= l1) {
                l2 = l1;
                l1 = cost[i];
            } else if (cost[i] > l2) {
                l2 = cost[i];
            }
        }
        if (l1 * 2 > l2 * 6) {
            res = l1 / 2;
        }
        res = max(res, min(l1, l2));
    }
    std::cout << res;
    return 0;
}