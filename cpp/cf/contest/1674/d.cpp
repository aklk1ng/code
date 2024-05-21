#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = n % 2; i < n; i += 2) {
        if (a[i] > a[i + 1]) {
            std::swap(a[i], a[i + 1]);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i - 1] > a[i]) {
            ok = false;
        }
    }
    std::cout << (ok ? "YES" : "NO") << '\n';
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
