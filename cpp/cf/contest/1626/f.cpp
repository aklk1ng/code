#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int L = 720720;

int add(int x, int y, int m = mod) {
    x += y;
    if (x >= m) {
        x -= m;
    }
    return x;
}

int mul(int x, int y, int m = mod) { return (x * 1ll * y) % m; }

int pow(int x, int y) {
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

int inv(int x) { return pow(x, mod - 2); }

int divide(int x, int y) { return mul(x, inv(y)); }

void solve() {
    int n, a0, x, y, k, M;
    std::cin >> n >> a0 >> x >> y >> k >> M;

    std::vector<int> arr(n);
    arr[0] = a0;
    for (int i = 1; i < n; i++) {
        arr[i] = add(mul(arr[i - 1], x, M), y, M);
    }
    int ans = 0;
    int total = pow(n, k);
    int coeff = mul(divide(total, n), k);
    std::vector<std::vector<int>> dp(k, std::vector<int>(L));
    for (int i = 0; i < n; i++) {
        int p = arr[i] / L;
        int q = arr[i] % L;
        dp[0][q]++;
        ans = add(ans, mul(p, mul(L, coeff)));
    }
    int cur_coeff = divide(total, n);
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < L; j++) {
            int cur = dp[i - 1][j];
            if (i < k) {
                dp[i][j] = add(dp[i][j], mul(n - 1, cur));
            }
            ans = add(ans, mul(j, mul(cur, cur_coeff)));
            if (i < k) {
                dp[i][j - (j % i)] = add(dp[i][j - (j % i)], cur);
            }
        }
        cur_coeff = divide(cur_coeff, n);
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
