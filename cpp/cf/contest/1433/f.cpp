#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 75;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    int dp[N][N][N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int cnt = 0; cnt < N; cnt++) {
                for (int rem = 0; rem < N; rem++) {
                    dp[i][j][cnt][rem] = INT_MIN;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int cnt = 0; cnt < m / 2 + 1; cnt++) {
                for (int rem = 0; rem < k; rem++) {
                    if (dp[i][j][cnt][rem] == INT_MIN) {
                        continue;
                    }
                    int ni = (j == m - 1 ? i + 1 : i);
                    int nj = (j == m - 1 ? 0 : j + 1);
                    if (i != ni) {
                        dp[ni][nj][0][rem] =
                            std::max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
                    } else {
                        dp[ni][nj][cnt][rem] =
                            std::max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
                    }
                    if (cnt + 1 <= m / 2) {
                        int nrem = (rem + a[i][j]) % k;
                        if (i != ni) {
                            dp[ni][nj][0][nrem] =
                                std::max(dp[ni][nj][0][nrem],
                                         dp[i][j][cnt][rem] + a[i][j]);
                        } else {
                            dp[ni][nj][cnt + 1][nrem] =
                                std::max(dp[ni][nj][cnt + 1][nrem],
                                         dp[i][j][cnt][rem] + a[i][j]);
                        }
                    }
                }
            }
        }
    }

    std::cout << std::max(0, dp[n][0][0][0]) << '\n';
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
