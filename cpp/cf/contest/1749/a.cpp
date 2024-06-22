#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }

    bool ok = false;
    for (int i = 0; i < m; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if ((x == a[i].first) ^ (y == a[i].second)) {
                    bool flag = true;
                    for (int j = 0; j < m; j++) {
                        if (i != j) {
                            flag &= x != a[j].first && y != a[j].second;
                        }
                    }
                    ok |= flag;
                }
            }
        }
    }
    std::cout << (ok ? "Yes" : "No") << '\n';
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
