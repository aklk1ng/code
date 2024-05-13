#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    bool ok = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[0]) {
            std::swap(s[i], s[0]);
            ok = true;
            break;
        }
    }

    if (!ok) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    std::cout << s << '\n';
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
