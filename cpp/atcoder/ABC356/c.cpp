#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector key(m, std::vector<int>(n));
    std::vector<std::string> r(m);
    for (int i = 0; i < m; i++) {
        int c;
        std::cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            std::cin >> a;
            key[i][a - 1] = 1;
        }
        std::cin >> r[i];
    }

    int ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        std::vector<int> t(n);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                t[j] = 1;
            } else {
                t[j] = 0;
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            int ck = 0;
            for (int p = 0; p < n; p++) {
                if (key[j][p] == 1 && t[p] == 1) {
                    ck++;
                }
            }
            if (ck >= k && r[j] == "x") {
                ok = false;
            }
            if (ck < k && r[j] == "o") {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }
    std::cout << ans << '\n';
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
