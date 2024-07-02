#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const ll N = 2e5 + 5, LG = 18;
int lf[LG][N], msb[N];
int v[N];

int n, m;
std::vector<std::vector<ll>> dp, sum;

int leftmost_maximum_query(int l, int r) {
    int bit = msb[r - l + 1];
    if (v[lf[bit][l]] >= v[lf[bit][r - (1 << bit) + 1]]) {
        return lf[bit][l];
    } else {
        return lf[bit][r - (1 << bit) + 1];
    }
}

int divide(int l, int r) {

    if (l > r) {
        return -1;
    }

    int mid = leftmost_maximum_query(l, r);

    int p = divide(l, mid - 1), p2 = divide(mid + 1, r);

    for (int i = 1; i <= m; i++) {
        if (p != -1 && i == 1) {
            dp[mid][1] = 0;
        } else {
            dp[mid][i] = (p >= 0 ? sum[p][i - 1] : 1ll) *
                         (p2 >= 0 ? sum[p2][i] : 1ll) % mod;
        }

        sum[mid][i] = (sum[mid][i - 1] + dp[mid][i]) % mod;
    }
    return mid;
}

void init() {
    for (int i = 2; i < N; i++) {
        msb[i] = msb[i - 1] + ((i & (i - 1)) == 0);
    }
}

void solve() {
    std::cin >> n >> m;
    dp.resize(n), sum.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        lf[0][i] = i;

        dp[i].resize(m + 1), sum[i].resize(m + 1);
        for (int j = 0; j <= m; j++) {
            dp[i][j] = sum[i][j] = 0;
        }
    }

    for (int bit = 1; bit < LG; bit++) {
        for (int i = 0; i + (1 << bit) <= n; i++) {
            if (v[lf[bit - 1][i]] >= v[lf[bit - 1][i + (1 << (bit - 1))]]) {
                lf[bit][i] = lf[bit - 1][i];
            } else {
                lf[bit][i] = lf[bit - 1][i + (1 << (bit - 1))];
            }
        }
    }
    divide(0, n - 1);
    std::cout << sum[leftmost_maximum_query(0, n - 1)][m] << '\n';
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
