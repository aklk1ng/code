#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 128;

ll add(ll x, ll y) { return (x + y) % mod; }

ll mul(ll x, ll y) { return x * y % mod; }

std::vector<int> g[N];
bool used[N];
int cnt[N];
ll dp[N][N];

ll cal(int m, int k) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], cnt[i]));
        }
    return dp[m][k];
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    if (k == 2) {
        std::cout << n * (n - 1LL) / 2 % mod << '\n';
        return;
    }
    ll ans = 0;
    for (int center = 0; center < n; center++) {
        memset(used, 0, n);
        used[center] = true;

        std::vector<std::pair<int, int>> layer;
        int m = g[center].size();
        for (int i = 0; i < m; i++) {
            int y = g[center][i];
            layer.emplace_back(y, i);
            cnt[i] = 1;
            used[y] = true;
        }
        while (!layer.empty()) {
            ans = add(ans, cal(m, k));
            std::vector<std::pair<int, int>> newlayer;
            for (auto p : layer) {
                cnt[p.second]--;
                for (auto y : g[p.first])
                    if (!used[y]) {
                        newlayer.emplace_back(y, p.second);
                        used[y] = true;
                        cnt[p.second]++;
                    }
            }
            layer = newlayer;
        }
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
