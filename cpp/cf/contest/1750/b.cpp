#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    s = '$' + s;
    ll cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }
    ll ans = cnt0 * cnt1;
    ll lg = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            lg++;
        } else {
            ans = std::max(ans, lg * lg);
            lg = 1;
        }
    }
    ans = std::max(ans, lg * lg);
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
