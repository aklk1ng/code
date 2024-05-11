#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::vector<int>> g;
std::vector<bool> todo, good;

void dfs(int v, int p = -1) {
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v);
            if (todo[u]) {
                todo[v] = true;
            }
            if (good[u]) {
                good[v] = true;
            }
        }
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    g.clear();
    g.resize(n);
    int x, y;
    std::cin >> x >> y;
    --x;
    --y;
    todo.resize(n);
    std::fill(todo.begin(), todo.end(), false);
    good.resize(n);
    std::fill(good.begin(), good.end(), false);
    for (int i = 0; i < k; ++i) {
        int v;
        std::cin >> v;
        --v;
        todo[v] = true;
    }
    good[y] = true;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        std::cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(x);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == x) {
            continue;
        }
        if (good[i]) {
            ++ans;
        } else if (todo[i]) {
            ans += 2;
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
