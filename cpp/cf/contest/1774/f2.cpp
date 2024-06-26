#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 800005;
int n, m;
ll a[N], b[N], c[N], cnt, s[N], d[N], cntd;

void solve() {
    std::cin >> n;
    ll maxs = 1e9, sum = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] != 3) {
            std::cin >> b[i];
        }
        if (a[i] == 2) {
            sum += b[i];
        }
        sum = std::min(sum, maxs);
        if (a[i] == 3) {
            b[i] = sum, sum = sum * 2;
        }
        sum = std::min(sum, maxs);
    }
    sum = 0;
    ll res = 1, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 2) {
            sum += b[i];
        } else if (a[i] == 3) {
            if (b[i] == maxs) {
                continue;
            }
            if (b[i] == 0) {
                res = res * 2 % mod;
                continue;
            }
            c[++cnt] = b[i];
        } else {
            b[i] -= sum;
            if (b[i] <= 0) {
                continue;
            }
            ll su = 0, r = b[i];
            for (int j = 1; j <= cnt; j++) {
                if (r > c[j]) {
                    su = (su + (1ll << (cnt - j))) % mod;
                    r -= c[j];
                }
            }
            su = (su + 1) % mod;
            ans = (ans + su * res) % mod;
        }
    }
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
