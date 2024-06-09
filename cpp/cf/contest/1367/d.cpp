#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<std::vector<int>> groups;
    while (true) {
        std::vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (!b[i]) {
                pos.push_back(i);
            }
        }
        if (pos.empty()) {
            break;
        }
        groups.push_back(pos);
        for (int i = 0; i < n; i++) {
            if (!b[i]) {
                b[i] = INT_MAX;
            } else {
                for (auto &e : pos) {
                    b[i] -= std::abs(i - e);
                }
            }
        }
    }
    std::map<char, int> cnt;
    for (auto &e : s) {
        cnt[e]++;
    }
    auto j = cnt.rbegin();
    std::string t(n, '?');
    for (auto &g : groups) {
        while (j->second < g.size()) {
            j++;
        }
        for (auto &e : g) {
            t[e] = j->first;
        }
        j++;
    }
    std::cout << t << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
