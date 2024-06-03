#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 111;

int n, k;
int a[N];
int nxtx[N][N], prvx[N][N];
int nxtnx[N][N], prvnx[N][N];
int dp1[N][N][N], dp2[N][N][N];

int calc2(int, int, int);

int calc1(int l, int r, int x) {
    l = nxtnx[l][x], r = prvnx[r][x];
    if (l > r) {
        return 0;
    }
    if (dp1[l][r][x] != -1) {
        return dp1[l][r][x];
    }
    dp1[l][r][x] = calc2(l, r, x) + 1;
    for (int i = l; i < r; ++i) {
        dp1[l][r][x] =
            std::min(dp1[l][r][x], calc1(l, i, x) + calc1(i + 1, r, x));
    }
    return dp1[l][r][x];
}

int calc2(int l, int r, int x) {
    l = nxtx[l][x], r = prvx[r][x];
    if (l > r) {
        return 0;
    }
    if (dp2[l][r][x] != -1) {
        return dp2[l][r][x];
    }
    dp2[l][r][x] = n;
    for (int i = l; i < r; ++i) {
        dp2[l][r][x] =
            std::min(dp2[l][r][x], calc2(l, i, x) + calc2(i + 1, r, x));
    }
    for (int y = 0; y < k; ++y) {
        if (x != y) {
            dp2[l][r][x] = std::min(dp2[l][r][x], calc1(l, r, y));
        }
    }
    return dp2[l][r][x];
}

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i], --a[i];
    }

    for (int x = 0; x < k; ++x) {
        prvx[0][x] = prvnx[0][x] = -1;
    }
    for (int i = 0; i < n; ++i) {
        prvx[i][a[i]] = i;
        for (int x = 0; x < k; ++x) {
            prvx[i + 1][x] = prvx[i][x];
        }
        for (int x = 0; x < k; ++x) {
            if (x != a[i]) {
                prvnx[i][x] = i;
            }
        }
        for (int x = 0; x < k; ++x) {
            prvnx[i + 1][x] = prvnx[i][x];
        }
    }
    for (int x = 0; x < k; ++x) {
        nxtx[n][x] = nxtnx[n][x] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int x = 0; x < k; ++x) {
            nxtx[i][x] = nxtx[i + 1][x];
        }
        nxtx[i][a[i]] = i;
        for (int x = 0; x < k; ++x) {
            nxtnx[i][x] = nxtnx[i + 1][x];
        }
        for (int x = 0; x < k; ++x) {
            if (x != a[i]) {
                nxtnx[i][x] = i;
            }
        }
    }
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int ans = n;
    for (int x = 0; x < k; ++x) {
        ans = std::min(ans, calc1(0, n - 1, x));
    }
    std::cout << ans << '\n';
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
