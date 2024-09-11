#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(a.back() + x);
    }
    std::string s;
    std::cin >> s;

    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        while (l < n && s[l] == 'R') {
            l++;
        }
        while (r >= 0 && s[r] == 'L') {
            r--;
        }
        if (l < r) {
            ans += a[r + 1] - a[l];
            l++;
            r--;
        }
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
