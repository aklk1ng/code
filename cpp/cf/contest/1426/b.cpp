#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(2, std::vector<int>(2)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                std::cin >> a[i][j][k];
            }
        }
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (a[i][0][1] == a[i][1][0]) {
            ok = true;
            break;
        }
    }
    if (ok && m % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
