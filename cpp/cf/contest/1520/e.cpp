#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int cnt = 0;
    for (auto &c : s) {
        cnt += (c == '*' ? 1 : 0);
    }
    int pos = -1, cur = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (s[i] == '*') {
                cur++;
                if (cur == cnt / 2) {
                    pos = i;
                }
            }
        }
    }
    ll ans = 0;
    cur = pos - cnt / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            ans += std::abs(cur - i);
            cur++;
        }
    }
    std::cout << ans << '\n';
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
