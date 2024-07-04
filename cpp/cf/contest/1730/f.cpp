#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 5005;
const int K = 8;

int n, k, p[N], pos[N], dp[N][1 << K], t[N];

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & r + 1) - 1) {
        res += t[r];
    }
    return res;
}

void inc(int i, int d) {
    for (; i < N; i |= i + 1) {
        t[i] += d;
    }
}

int inv(int mn, int mask, int x) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        if ((mask & (1 << i)) && pos[x] < pos[mn + 1 + i]) {
            res++;
        }
    }
    res += sum(N - 1) - sum(pos[x]);
    return res;
}

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;

        pos[p[i]] = i;
    }

    for (int mn = 0; mn <= n; mn++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            dp[mn][mask] = 1e9;
        }
    }

    dp[0][0] = 0;

    for (int mn = 0; mn < n; mn++) {
        for (int mask = 0; mask < (1 << std::min(k, n - mn - 1)); mask++) {
            for (int i = 0; i < std::min(k, n - mn - 1); i++) {
                if ((mask & (1 << i)) == 0) {
                    dp[mn][mask + (1 << i)] =
                        std::min(dp[mn][mask + (1 << i)],
                                 dp[mn][mask] + inv(mn, mask, mn + 1 + i));
                }
            }

            int mn2 = mn, mask2 = mask;

            mn2++;

            while (mask2 % 2) {
                mn2++;
                mask2 /= 2;
            }

            mask2 /= 2;

            dp[mn2][mask2] =
                std::min(dp[mn2][mask2], dp[mn][mask] + inv(mn, mask, mn));
        }

        inc(pos[mn], 1);
    }

    std::cout << dp[n][0] << '\n';
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
