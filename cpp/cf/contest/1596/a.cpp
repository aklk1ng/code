#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n;
    std::cin >> n;
    std::cout << -n + 1 << ' ' << n << '\n';
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
