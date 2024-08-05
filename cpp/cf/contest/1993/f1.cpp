#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, k, w, h;
    std::string s;
    std::cin >> n >> k >> w >> h >> s;

    std::map<std::pair<ll, ll>, ll> cnt;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            x--;
        }
        if (s[i] == 'R') {
            x++;
        }
        if (s[i] == 'D') {
            y--;
        }
        if (s[i] == 'U') {
            y++;
        }

        x = (x + 2 * w) % (2 * w);
        y = (y + 2 * h) % (2 * h);
        cnt[{x, y}]++;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ll vx = (-i * x % (2 * w) + 2 * w) % (2 * w);
        ll vy = (-i * y % (2 * h) + 2 * h) % (2 * h);
        ans += cnt[{vx, vy}];
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
