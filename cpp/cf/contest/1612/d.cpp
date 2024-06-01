#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool get(ll a, ll b, ll x) {
    if (a == x || b == x) {
        return true;
    }
    if (a < b) {
        std::swap(a, b);
    }
    if (b > a - b) {
        b = a - b;
    }
    if (x > std::max(a, b) || a == 0 || b == 0) {
        return false;
    }
    ll cnt = std::max(1ll, (a - std::max(x, b)) / (2 * b));
    return get(a - b * cnt, b, x);
}

void solve() {
    ll a, b, x;
    std::cin >> a >> b >> x;

    if (get(a, b, x)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
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
