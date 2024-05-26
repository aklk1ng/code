#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            pos = i;
            break;
        }
    }
    if (!pos) {
        std::cout << "YES\n";
        return;
    }
    bool ok = false;
    for (int i = pos + 1; i <= n; i++) {
        int j = (i % n) + 1;
        if (a[i] > a[j]) {
            ok = true;
        }
    }
    std::cout << (ok ? "NO" : "YES") << '\n';
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
