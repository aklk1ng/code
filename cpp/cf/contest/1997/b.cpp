#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(2);
    for (int i = 0; i < 2; i++) {
        std::cin >> s[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        bool ok = true;
        ok &= (s[0][i] == '.' && s[1][i] == '.');
        ok &= (s[0][i - 1] != s[1][i - 1]);
        ok &= (s[0][i + 1] != s[1][i + 1]);
        ok &= (s[0][i - 1] == s[0][i + 1]);
        ans += ok;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
