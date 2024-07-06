#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int comp(char c, char d) { return c < d ? -1 : (c > d ? 1 : 0); }

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector dp(n + 1, std::vector<int>(n + 1));
    for (int len = 2; len <= n; len += 2) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len;
            dp[l][r] = 1;
            {
                int res = -1;
                if (dp[l + 1][r - 1]) {
                    res = std::max(res, dp[l + 1][r - 1]);
                } else {
                    res = std::max(res, comp(s[l], s[r - 1]));
                }
                if (dp[l + 2][r]) {
                    res = std::max(res, dp[l + 2][r]);
                } else {
                    res = std::max(res, comp(s[l], s[l + 1]));
                }
                dp[l][r] = std::min(dp[l][r], res);
            }
            {
                int res = -1;
                if (dp[l + 1][r - 1]) {
                    res = std::max(res, dp[l + 1][r - 1]);
                } else {
                    res = std::max(res, comp(s[r - 1], s[l]));
                }
                if (dp[l][r - 2]) {
                    res = std::max(res, dp[l][r - 2]);
                } else {
                    res = std::max(res, comp(s[r - 1], s[r - 2]));
                }
                dp[l][r] = std::min(dp[l][r], res);
            }
        }
    }
    if (dp[0][n] == -1) {
        std::cout << "Alice\n";
    } else if (dp[0][n] == 0) {
        std::cout << "Draw\n";
    } else {
        std::cout << "Bob\n";
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
