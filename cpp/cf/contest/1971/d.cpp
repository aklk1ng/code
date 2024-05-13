#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int ans = 1;
    bool ok = false;
    for (int i = 0; i < s.size() - 1; i++) {
        ans += (s[i] != s[i + 1]);
        ok |= (s[i] == '0' && s[i + 1] == '1');
    }
    std::cout << ans - ok << '\n';
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
