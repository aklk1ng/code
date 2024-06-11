#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct SegmentTree {
    int n;
    std::vector<std::vector<int>> tree;

    void build(std::vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = {a[l]};
            return;
        }

        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        merge(tree[2 * x + 1].begin(), tree[2 * x + 1].end(),
              tree[2 * x + 2].begin(), tree[2 * x + 2].end(),
              back_inserter(tree[x]));
    }

    SegmentTree(std::vector<int> &a) : n(a.size()) {
        int SIZE = 1 << (std::__lg(n) + bool(__builtin_popcount(n) - 1));
        tree.resize(2 * SIZE - 1);
        build(a, 0, 0, n);
    }

    int count(int lq, int rq, int mn, int mx, int x, int l, int r) {
        if (rq <= l || r <= lq)
            return 0;
        if (lq <= l && r <= rq)
            return std::lower_bound(tree[x].begin(), tree[x].end(), mx) -
                   std::lower_bound(tree[x].begin(), tree[x].end(), mn);

        int m = (l + r) / 2;
        int a = count(lq, rq, mn, mx, 2 * x + 1, l, m);
        int b = count(lq, rq, mn, mx, 2 * x + 2, m, r);
        return a + b;
    }

    int count(int lq, int rq, int mn, int mx) {
        return count(lq, rq, mn, mx, 0, 0, n);
    }
};

std::vector<std::vector<int>> g;

std::vector<int> tin, tout;
int timer;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = timer;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    g.assign(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    dfs(0, -1);

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = tin[p[i] - 1];
    }
    SegmentTree ST(a);

    for (int i = 0; i < q; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--;
        x--;
        if (ST.count(l, r, tin[x], tout[x])) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
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
    while (T--) {
        solve();
    }

    return 0;
}
