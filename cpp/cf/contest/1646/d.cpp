#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 400005;

std::vector<int> g[N];

bool vis[N];
int pa[N];

void dfs(int v) {
    vis[v] = 1;
    for (auto i : g[v]) {
        if (!vis[i]) {
            pa[i] = v;
            dfs(i);
        }
    }
}

std::pair<int, int> dp[N][2];

std::pair<int, int> f(int x, int y) {
    std::pair<int, int> &res = dp[x][y];
    if (res.first >= 0) {
        return res;
    }
    res = {y, y ? -((int)g[x].size()) : -1};
    for (auto i : g[x]) {
        if (i != pa[x]) {
            std::pair<int, int> maxi = f(i, 0);
            if (y == 0) {
                maxi = max(maxi, f(i, 1));
            }
            res.first += maxi.first;
            res.second += maxi.second;
        }
    }
    return res;
}

std::vector<int> good;

void build(std::pair<int, int> value, int v) {
    if (value == f(v, 0)) {
        good[v] = 0;
        for (auto i : g[v]) {
            if (i != pa[v]) {
                build(max(f(i, 0), f(i, 1)), i);
            }
        }
    } else {
        good[v] = 1;
        for (auto i : g[v]) {
            if (i != pa[v]) {
                build(f(i, 0), i);
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 2) {
        std::cout << "2 2\n1 1\n";
        return;
    }
    pa[0] = -1;
    dfs(0);
    for (int i = 0; i < n; i++) {
        dp[i][0] = {-1, -1}, dp[i][1] = {-1, -1};
    }
    std::pair<int, int> res = max(f(0, 0), f(0, 1));
    std::cout << res.first << " " << -res.second << "\n";
    good.resize(n);
    build(res, 0);
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            std::cout << g[i].size() << " ";
        } else {
            std::cout << "1 ";
        }
    }
    std::cout << "\n";
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
