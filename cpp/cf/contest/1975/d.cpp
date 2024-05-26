#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e5 + 10;

std::vector<int> g[N];
int dep[N], f[N], mx, n, a, b;

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    mx = std::max(mx, dep[x]);
    f[x] = fa;
    for (auto i : g[x]) {
        if (i == fa) {
            continue;
        }
        dfs(i, x);
    }
}

std::vector<int> move(int x, int y) {
    if (dep[x] > dep[y]) {
        std::swap(x, y);
    }
    std::vector<int> track, ano;
    int tmp = dep[y] - dep[x], ans = 0;
    track.push_back(y);
    while (tmp--) {
        y = f[y];
        track.push_back(y);
    }
    if (y == x) {
        return track;
    }
    ano.push_back(x);
    while (f[x] != f[y]) {
        x = f[x];
        y = f[y];
        ano.push_back(x);
        track.push_back(y);
    }
    track.push_back(f[y]);
    std::reverse(ano.begin(), ano.end());
    for (auto i : ano) {
        track.push_back(i);
    }
    return track;
}

void solve() {
    mx = -1;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    std::cin >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (a == b) {
        dfs(a, 0);
        std::cout << 2 * (n - 1) - mx << '\n';
        return;
    }
    dfs(1, 0);
    auto tr = move(a, b);
    int m = tr.size();
    if (tr[0] != a) {
        std::reverse(tr.begin(), tr.end());
    }
    int x = tr[(m - 1) / 2];
    mx = -1;
    dfs(x, 0);
    std::cout << 2 * (n - 1) - mx + (m - 1 - (m - 1) / 2) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    dep[0] = -1;
    while (T--) {
        solve();
    }

    return 0;
}
