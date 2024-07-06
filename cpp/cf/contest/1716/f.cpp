#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2043;

int dp[N][N];

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int sub(int x, int y) { return add(x, -y); }

int mul(int x, int y) { return (x * 1ll * y) % mod; }

int binpow(int x, int y) {
    int z = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            z = mul(z, x);
        }
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x) { return binpow(x, mod - 2); }

int divide(int x, int y) { return mul(x, inv(y)); }

void init() {
    dp[1][1] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], j));
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
        }
    }
}

int solve(int n, int m, int k) {
    int way1 = (m / 2) + (m % 2);
    int curA = n;
    int ans = 0;
    int ways_chosen = way1;
    int ways_other = binpow(m, n - 1);
    int invm = inv(m);
    for (int i = 1; i <= k; i++) {
        ans = add(ans, mul(mul(curA, dp[k][i]), mul(ways_chosen, ways_other)));
        curA = mul(curA, sub(n, i));
        ways_chosen = mul(way1, ways_chosen);
        ways_other = mul(ways_other, invm);
    }
    return ans;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::cout << solve(n, m, k) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    init();
    while (_--) {
        solve();
    }

    return 0;
}
