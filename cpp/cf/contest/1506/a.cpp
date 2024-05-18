#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, m, x;
    std::cin >> n >> m >> x;

    x--;
    ll col = x / n;
    ll row = x % n;
    std::cout << row * m + col + 1 << '\n';
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
