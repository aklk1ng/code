#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 16;

int n, m;
int a[N][N];

int fr[N][N], fc[N][N];
int w[N][N], dp[N][1 << N];

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        a[i][m] = 0;
    }
    for (int j = 0; j <= m; j++) {
        a[n][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            a[i][m] ^= a[i][j];
            a[n][j] ^= a[i][j];
            a[n][m] ^= a[i][j];
        }
    }

    int fullmask_n = (1 << (n + 1)) - 1;
    int fullmask_m = (1 << (m + 1)) - 1;

    for (int rmv = 0; rmv <= m; rmv++) {
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                w[i][j] = 0;
                for (int l = 0; l <= m; l++) {
                    if (rmv == l) {
                        continue;
                    }
                    w[i][j] += abs(a[i][l] - a[j][l]);
                }
                w[j][i] = w[i][j];
            }
        }
        for (int i = 0; i <= n; i++) {
            std::fill(dp[i], dp[i] + fullmask_n, INT_MAX);
            dp[i][1 << i] = 0;
        }
        for (int mask = 0; mask <= fullmask_n; mask++) {
            for (int last = 0; last <= n; last++) {
                if (~mask >> last & 1) {
                    continue;
                }
                if (__builtin_popcount(mask) == n) {
                    continue;
                }

                for (int next = 0; next <= n; next++) {
                    if (mask >> next & 1) {
                        continue;
                    }

                    int new_mask = mask | 1 << next;
                    dp[next][new_mask] = std::min(
                        dp[next][new_mask], dp[last][mask] + w[last][next]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            fr[i][rmv] = INT_MAX;
            int mask = fullmask_n ^ 1 << i;

            for (int last = 0; last <= n; last++) {
                fr[i][rmv] = std::min(fr[i][rmv], dp[last][mask]);
            }
        }
    }

    for (int rmv = 0; rmv <= n; rmv++) {
        for (int i = 0; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                w[i][j] = 0;
                for (int l = 0; l <= n; l++) {
                    if (rmv == l) {
                        continue;
                    }
                    w[i][j] += abs(a[l][i] - a[l][j]);
                }
                w[j][i] = w[i][j];
            }
        }

        for (int i = 0; i <= m; i++) {
            std::fill(dp[i], dp[i] + fullmask_m, INT_MAX);
            dp[i][1 << i] = 0;
        }

        for (int mask = 0; mask <= fullmask_m; mask++) {
            for (int last = 0; last <= m; last++) {
                if (~mask >> last & 1) {
                    continue;
                }
                if (__builtin_popcount(mask) == m) {
                    continue;
                }

                for (int next = 0; next <= m; next++) {
                    if (mask >> next & 1) {
                        continue;
                    }

                    int new_mask = mask | 1 << next;
                    dp[next][new_mask] = std::min(
                        dp[next][new_mask], dp[last][mask] + w[last][next]);
                }
            }
        }

        for (int i = 0; i <= m; i++) {
            fc[rmv][i] = INT_MAX;
            int mask = fullmask_m ^ 1 << i;

            for (int last = 0; last <= m; last++) {
                fc[rmv][i] = std::min(fc[rmv][i], dp[last][mask]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans = std::min(ans, fr[i][j] + fc[i][j]);
        }
    }
    std::cout << ans << '\n';
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
