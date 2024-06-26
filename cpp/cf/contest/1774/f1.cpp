#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int inv = (mod + 1) / 2;
std::map<ll, ll> s;
ll tot, mul = 1, ts = 1;

inline void add(ll &x, ll y) { (x += y) >= mod && (x -= mod); }

void solve() {
    int n;
    std::cin >> n;
    while (n--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            ll x;
            std::cin >> x;
            add(s[x + tot], ts);
        } else if (op == 2) {
            ll x;
            std::cin >> x;
            tot += x;
        } else if (tot <= 2e5) {
            if (!tot) {
                mul = mul * 2 % mod;
                ts = ts * inv % mod;
            } else {
                for (ll i = tot + 2e5; i > tot; i--) {
                    add(s[i + tot], s[i]);
                }
                tot *= 2;
            }
        }
    }
    ll ans = 0;
    for (auto &e : s) {
        if (e.first > tot) {
            add(ans, e.second);
        }
    }
    ans = ans * mul % mod;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
