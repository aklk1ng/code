#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(2);
    for (int i = 0; i < 2; i++) {
        std::cin >> s[i];
    }

    std::vector<std::array<std::array<int, 2>, 2>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INT_MIN;
        }
    }
    dp[0][0][s[1][0] == '1'] = s[1][0] == '1';
    dp[0][0][0] = 0;
    for (int i = 0; i <= n - 2; i++)
        for (int j = 0; j < 2; j++) {
            int nxtj = s[j][i + 1] == '1';
            int nxtj1 = s[j ^ 1][i + 1] == '1';
            dp[i + 1][j ^ 1][0] =
                std::max(dp[i + 1][j ^ 1][0], dp[i][j][1] + nxtj1);
            dp[i + 1][j][nxtj1] =
                std::max(dp[i + 1][j][nxtj1], dp[i][j][0] + nxtj1 + nxtj);
            dp[i + 1][j][0] = std::max(dp[i + 1][j][0], dp[i][j][0] + nxtj);
        }
    std::cout << std::max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0],
                           dp[n - 1][1][1]})
              << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
