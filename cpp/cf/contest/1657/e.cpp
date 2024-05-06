#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}

int mul(int a, int b) { return a * 1ll * b % mod; }

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    n--;
    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1)), C(n + 1);
    for (int i = 0; i <= n; i++) {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int t = 0; t <= n; t++) {
            int p = pow(k - i, t * (t - 1) / 2);
            int s = pow(k - i, t);
            for (int j = 0; j <= n - t; j++) {
                dp[i + 1][j + t] =
                    add(dp[i + 1][j + t], mul(dp[i][j], mul(C[n - j][t], p)));
                p = mul(p, s);
            }
        }
    }
    std::cout << dp[k][n] << '\n';
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
