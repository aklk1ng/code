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
    std::vector<int> b(n + 1, -1);
    std::vector<bool> vis(1e5 + 5);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            vis[b[i]] = true;
        }
    }
    vis[a[n]] = true;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        while (vis[m]) {
            m++;
        }
        if (b[i] == -1) {
            b[i] = m;
            vis[m] = true;
        }
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
