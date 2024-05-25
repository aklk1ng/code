#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int na = b - (c - b);
    if (na >= a && na % a == 0 && na) {
        std::cout << "YES\n";
        return;
    }

    int nb = a + (c - a) / 2;
    if (nb >= b && (c - a) % 2 == 0 && nb % b == 0 && nb) {
        std::cout << "YES\n";
        return;
    }

    int nc = a + 2 * (b - a);
    if (nc >= c && nc % c == 0 && nc) {
        std::cout << "YES\n";
        return;
    }
    std::cout << "NO\n";
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
