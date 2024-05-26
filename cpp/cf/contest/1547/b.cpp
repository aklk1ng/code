#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    size_t l = s.find('a');
    if (l == std::string::npos) {
        std::cout << "NO\n";
        return;
    }
    size_t n = s.length(), r = l;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        size_t pos = s.find(char('a' + i));
        if (pos == std::string::npos || (pos != l - 1 && pos != r + 1)) {
            ok = false;
            break;
        } else {
            l = std::min(l, pos);
            r = std::max(r, pos);
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
