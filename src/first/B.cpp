#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<string, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        pair<int, int> p(k, i);
        m[s].push_back(p);
    }
    vector<pair<int, string>> m2;
    for (auto &x : m) {
        sort(x.second.begin(), x.second.end(), greater<pair<int, int>>());
        int sum = 0;
        for (auto &e : x.second) {
            sum += e.first;
        }
        pair<int, string> p(sum, x.first);
        m2.push_back(p);
    }
    sort(m2.begin(), m2.end(), greater<pair<int, string>>());
    vector<int> result;
    for (int i = 0, size = m2.size(); i < size; i++) {
        string s = m2[i].second;
        for (int k = 0, size2 = m[s].size(); k < 2 && k < size2; k++) {
            result.push_back(m[s][k].second);
        }
    }
    for (int i = 0, size = result.size(); i < size; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}