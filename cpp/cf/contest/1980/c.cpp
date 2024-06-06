#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    int m;
    std::cin >> m;
    std::vector<int> d(m);
    for (int i = 0; i < m; i++) {
        std::cin >> d[i];
    }

    int ans = 1;
    if (std::find(b.begin(), b.end(), d[m - 1]) == b.end()) {
        ans = 0;
    }
    std::multiset s(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            if (!s.contains(b[i])) {
                ans = 0;
            }
            s.extract(b[i]);
        }
    }
    std::cout << (ans ? "YES" : "NO") << '\n';
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
