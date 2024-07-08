#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector val(3, std::vector<ll>(n + 1)), pf(3, std::vector<ll>(n + 1));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> val[i][j];
            pf[i][j] = pf[i][j - 1] + val[i][j];
        }
    }

    bool ok = false;
    std::vector<ll> perm = {0, 1, 2};
    ll comp = (pf[perm[0]][n] + 2) / 3;
    for (int i = 0; i < 6; i++) {
        int cur = 1;
        while (cur <= n && pf[perm[0]][cur] < comp) {
            cur++;
        }
        for (int j = cur + 1; j < n; j++) {
            if (pf[perm[1]][j] - pf[perm[1]][cur] >= comp &&
                pf[perm[2]][n] - pf[perm[2]][j] >= comp) {
                std::vector<std::pair<int, int>> ans(3);
                ans[perm[0]] = {1, cur};
                ans[perm[1]] = {cur + 1, j};
                ans[perm[2]] = {j + 1, n};

                for (auto &e : ans) {
                    std::cout << e.first << ' ' << e.second
                              << " \n"[e == ans.back()];
                }
                return;
            }
        }
        std::next_permutation(perm.begin(), perm.end());
    }
    std::cout << "-1\n";
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
