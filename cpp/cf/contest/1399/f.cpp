#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::vector<int>> rg;
std::vector<std::vector<int>> dp;

int calc(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = 0;
    if (l > r) {
        return dp[l][r];
    }
    bool add = count(rg[l].begin(), rg[l].end(), r);
    dp[l][r] = std::max(dp[l][r], add + (l + 1 > r ? 0 : calc(l + 1, r)));
    for (auto nr : rg[l]) {
        if (nr >= r) {
            continue;
        }
        dp[l][r] = std::max(dp[l][r], add + calc(l, nr) +
                                          (nr + 1 > r ? 0 : calc(nr + 1, r)));
    }
    return dp[l][r];
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> l(n), r(n);
    std::vector<int> val;
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
        val.push_back(l[i]);
        val.push_back(r[i]);
    }

    std::sort(val.begin(), val.end());
    val.resize(std::unique(val.begin(), val.end()) - val.begin());
    for (int i = 0; i < n; ++i) {
        l[i] = std::lower_bound(val.begin(), val.end(), l[i]) - val.begin();
        r[i] = std::lower_bound(val.begin(), val.end(), r[i]) - val.begin();
    }
    int sz = val.size();
    dp = std::vector<std::vector<int>>(sz, std::vector<int>(sz, -1));
    rg = std::vector<std::vector<int>>(sz);
    for (int i = 0; i < n; ++i) {
        rg[l[i]].push_back(r[i]);
    }
    std::cout << calc(0, sz - 1) << '\n';
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
