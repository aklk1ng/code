#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 5e5 + 7;
int n, C, p[N];
ll a[N];

void solve() {
    std::cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::iota(p + 1, p + n + 1, 1);
    std::sort(p + 1, p + n + 1, [&](const int &u, const int &v) {
        return 1ll * u * C - a[u] < 1ll * v * C - a[v];
    });
    ll now = a[1];
    for (int i = 1, u; i <= n; i++) {
        u = p[i];
        if (u == 1) {
            continue;
        }
        if (1ll * u * C > now + a[u]) {
            std::cout << "No\n";
            return;
        }
        now += a[u];
    }
    std::cout << "Yes\n";
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
