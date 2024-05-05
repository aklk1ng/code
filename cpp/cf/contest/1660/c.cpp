#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int m = 0, n = s.size();
    std::vector<bool> pre(26);
    for (auto &c : s) {
        if (pre[c - 'a']) {
            m += 2;
            for (int j = 0; j < 26; j++) {
                pre[j] = false;
            }
        } else {
            pre[c - 'a'] = true;
        }
    }
    std::cout << n - m << '\n';
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
