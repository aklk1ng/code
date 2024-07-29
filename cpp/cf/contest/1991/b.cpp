#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);
    for (int i = 1; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = b[i - 1] | b[i];
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if ((a[i] & a[i + 1]) != b[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        for (int i = 1; i <= n; i++) {
            std::cout << a[i] << " \n"[i == n];
        }
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
