#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int maxn = 4e6 + 7;
const int N = 1e6;

int n, a[maxn], pr[maxn], tot, stk[maxn], top;
std::vector<bool> vis(maxn);

inline void init() {
    for (int i = 2; i <= N; ++i) {
        if (!vis[i]) {
            pr[++tot] = i;
        }
        for (int j = 1; j <= tot && i * pr[j] <= N; ++j) {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                break;
            }
        }
    }
    std::fill(vis.begin(), vis.end(), false);
}

inline bool check(int x) {
    if (x & 1) {
        return x + 1 + x * (x - 1) / 2 >= n;
    } else {
        return x * (x - 1) / 2 - x / 2 + 2 + x >= n;
    }
}

std::vector<std::pair<int, int>> G[10000];

void dfs(int u) {
    while (G[u].size()) {
        std::pair<int, int> p = G[u].back();
        G[u].pop_back();
        if (vis[p.second]) {
            continue;
        }
        vis[p.second] = 1;
        dfs(p.first);
    }
    stk[++top] = pr[u];
}

void solve() {
    std::cin >> n;
    int l = 1, r = 10000, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    for (int i = 1; i <= ans; ++i) {
        std::vector<std::pair<int, int>>().swap(G[i]);
    }
    int tot = 0;
    for (int i = 1; i <= ans; ++i) {
        for (int j = i; j <= ans; ++j) {
            if (ans % 2 == 0 && i % 2 == 0 && i + 1 == j) {
                continue;
            }
            G[i].push_back({j, ++tot});
            G[j].push_back({i, tot});
        }
    }
    for (int i = 1; i <= tot; ++i) {
        vis[i] = 0;
    }
    top = 0;
    dfs(1);
    std::reverse(stk + 1, stk + top + 1);
    for (int i = 1; i <= n; ++i) {
        std::cout << stk[i] << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    init();
    while (T--) {
        solve();
    }

    return 0;
}
