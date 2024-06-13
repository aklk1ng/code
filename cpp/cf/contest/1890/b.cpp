#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool ok(std::string s) {
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    std::string s, t;
    std::cin >> n >> m;
    std::cin >> s >> t;

    if (ok(s)) {
        std::cout << "YES\n";
        return;
    }
    if (!ok(t) || *t.begin() != *t.rbegin()) {
        std::cout << "NO\n";
        return;
    }
    int z = 0, o = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == '0') {
                z = true;
            }
            if (s[i] == '1') {
                o = true;
            }
        }
    }
    if (z && t[0] == '0') {
        std::cout << "NO\n";
        return;
    }
    if (o && t[0] == '1') {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
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
