#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    s = ' ' + s;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = (s[i] == '1' ? 1 : -1) + p[i - 1];
    }
    std::map<int, ll> cnt;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + (n - i + 1) * cnt[p[i]]) % mod;
        cnt[p[i]] = (cnt[p[i]] + (i + 1)) % mod;
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
