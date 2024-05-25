#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    bool ok = true;
    if (s.length() % 2 == 0) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[i + s.length() / 2]) {
                ok = false;
            }
        }
    } else {
        ok = false;
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
