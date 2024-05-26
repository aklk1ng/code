#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 24, S = (1 << 20) + 5;
int n = 0, f[N][S] = {};
std::vector<int> ans;

inline void dfs(int s = 0, int i = 0) {
    if (i < n) {
        int m = 1 << (n - i - 1);
        for (int t = 0; t < m; t++) {
            f[i + 1][t] = f[i][t] & f[i][m | t];
        }
        dfs(s << 1, i + 1);
        for (int t = 0; t < m; t++) {
            f[i + 1][t] = f[i][t] & (f[i][m | t] >> 1);
        }
        dfs(s << 1 | 1, i + 1);
    } else if (f[n][0] & 1) {
        ans.push_back(s);
    }
}

void solve() {
    std::cin >> n;
    f[0][0] = 1;
    for (int s = 1; s < 1 << n; s++) {
        std::cin >> f[0][s];
    }

    dfs();
    std::cout << ans.size() << '\n';
    for (int e : ans) {
        std::cout << e << '\n';
    }
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
