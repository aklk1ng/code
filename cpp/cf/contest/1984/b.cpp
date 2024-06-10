#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n;
    std::cin >> n;

    n = n - n % 10 + (n % 10 + 1) % 10;
    while (n > 9) {
        if (n % 10 == 0) {
            std::cout << "NO\n";
            return;
        }
        n /= 10;
    }
    std::cout << (n == 1 ? "YES\n" : "NO\n");
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
