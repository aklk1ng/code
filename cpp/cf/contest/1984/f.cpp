#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int BOUND;
    std::cin >> BOUND;
    std::string s;
    std::cin >> s;
    s = "P" + s + "S";
    std::vector<ll> b(n + 2);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i + 1];
    }

    ll ans = 0;
    std::set<ll> done;
    for (int i = 0; i < n + 1; ++i) {
        ll sum = b[i] + b[i + 1];
        if (done.count(sum)) {
            continue;
        }
        int dp[n + 2][2];
        for (int j = 0; j < n + 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[j][k] = -1;
            }
        }
        dp[0][0] = 1;
        for (int j = 1; j < n + 2; ++j) {
            bool tr[2];
            tr[0] = tr[1] = true;
            if (s[j] == 'P') {
                tr[1] = false;
            } else if (s[j] == 'S') {
                tr[0] = false;
            }
            if (std::abs(b[j] - b[j - 1]) <= BOUND) {
                for (int k = 0; k < 2; ++k) {
                    if (dp[j - 1][k] > -1 && tr[k]) {
                        dp[j][k] = dp[j - 1][k];
                    }
                }
            }
            if (dp[j - 1][0] > -1 && tr[1] && sum == b[j] + b[j - 1]) {
                if (dp[j][1] < 0) {
                    dp[j][1] = 0;
                }
                dp[j][1] = (dp[j][1] + dp[j - 1][0]) % mod;
            }
            if (dp[j - 1][1] > -1 && tr[0]) {
                ll add = b[j] + b[j - 1] - sum;
                ll large = std::max(std::abs(add / 2), std::abs(add - add / 2));
                if (large <= BOUND) {
                    if (dp[j][0] < 0) {
                        dp[j][0] = 0;
                    }
                    dp[j][0] = (dp[j][0] + dp[j - 1][1]) % mod;
                }
            }
        }
        if (dp[n + 1][1] < 0) {
            continue;
        }
        ans = (ans + dp[n + 1][1]) % mod;
        done.insert(sum);
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
