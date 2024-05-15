#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll a, b, c;
    std::cin >> a >> b >> c;

    ll n = 2 * std::abs(a - b);
    if (a > n || b > n || c > n) {
        std::cout << "-1\n";
    } else {
        ll d = n / 2 + c;
        while (d > n) {
            d -= n;
        }
        std::cout << d << '\n';
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
