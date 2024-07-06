#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(std::abs(a), std::abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) {
        x0 = -x0;
    }
    if (b < 0) {
        y0 = -y0;
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    ll cur = std::accumulate(b.begin(), b.end(), 0LL);
    std::vector<int> dif(n);
    for (int i = 0; i < n; i++) {
        dif[i] = a[i] - b[i];
    }
    std::sort(dif.begin(), dif.end(), std::greater<int>());
    std::vector<ll> bst(n + 1);
    for (int i = 0; i <= n; i++) {
        bst[i] = cur;
        if (i < n) {
            cur += dif[i];
        }
    }
    int mx = std::max_element(bst.begin(), bst.end()) - bst.begin();
    int m;
    std::cin >> m;
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        ll x0, y0, g;
        if (!find_any_solution(x, y, n, x0, y0, g)) {
            std::cout << "-1\n";
            continue;
        }
        ll l = x * 1LL * y / g;
        ll red = x0 * 1LL * x;
        red = red + (std::max(0LL, mx - red) + l - 1) / l * l;
        red = red - std::max(0LL, red - mx) / l * l;
        ll ans = -1;
        if (red <= n) {
            ans = std::max(ans, bst[red]);
        }
        red -= l;
        if (red >= 0) {
            ans = std::max(ans, bst[red]);
        }
        std::cout << ans << '\n';
    }
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
