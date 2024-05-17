#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, s, k;
    std::cin >> s >> n >> k;

    if (s == k) {
        std::cout << "YES\n";
    } else if (k > s) {
        std::cout << "NO\n";
    } else {
        ll posa = s + k;
        ll l = s - k + 1, r = s;
        ll sz = r - l + 1;
        ll a = 0, b = 0;
        ll num = (s / k) * k;
        b = r - num + 1;
        a = sz - b;
        if ((s / k) % 2) {
            posa -= b;
        } else {
            posa -= a;
        }
        if ((2 * n + 1) > posa) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
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
