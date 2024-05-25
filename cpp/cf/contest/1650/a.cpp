#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    bool ok = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[0] && i % 2 == 0) {
            ok = true;
        }
    }
    std::cout << (ok ? "YES" : "NO") << '\n';
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
