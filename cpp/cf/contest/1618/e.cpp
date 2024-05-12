#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n), a(n);
    ll sumb = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        sumb += b[i];
    }

    ll d = n * 1LL * (n + 1) / 2;
    if (sumb % d) {
        std::cout << "NO\n";
        return;
    }
    ll suma = sumb / d;
    for (int i = n - 1; i >= 0; i--) {
        ll res = (b[i] - b[(i + 1) % n] + suma);
        if (res % n || res <= 0) {
            std::cout << "NO\n";
            return;
        }
        a[(i + 1) % n] = res / n;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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
