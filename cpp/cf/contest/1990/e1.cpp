#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct Tree {
    int n;
    std::vector<std::vector<int>> adj, anc;
    std::vector<int> par, tl, tr, dep, ord, siz, ch, head;

    Tree(int _n = 0) {
        n = _n;
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init() {
        par.resize(n), tl.resize(n), tr.resize(n), dep.resize(n), anc.resize(n),
            siz.resize(n), ch.resize(n), head.resize(n);
        int cur = -1, m = 0;
        while ((1 << m) <= n) {
            m++;
        }
        for (int i = 0; i < n; ++i) {
            anc[i].resize(m), ch[i] = -1;
        }
        auto dfs1 = [&](auto &self, int u, int fa) -> void {
            par[u] = fa;
            siz[u] = 1;
            for (int v : adj[u]) {
                if (v != fa) {
                    self(self, v, u), siz[u] += siz[v];
                }
            }
            for (int v : adj[u]) {
                if (v != fa && (ch[u] == -1 || siz[v] > siz[ch[u]])) {
                    ch[u] = v;
                }
            }
        };
        auto dfs2 = [&](auto &self, int u, int fa) -> void {
            ord.push_back(u);
            tl[u] = ++cur;
            anc[u][0] = fa;
            if (fa == -1) {
                dep[u] = 0;
            } else {
                dep[u] = dep[fa] + 1;
            }
            for (int i = 1; i < m; ++i) {
                if (anc[u][i - 1] == -1) {
                    anc[u][i] = -1;
                } else {
                    anc[u][i] = anc[anc[u][i - 1]][i - 1];
                }
            }
            if (ch[u] != -1) {
                self(self, ch[u], u);
            }
            for (int v : adj[u]) {
                if (v != fa && v != ch[u]) {
                    self(self, v, u);
                }
            }
            tr[u] = cur;
        };
        dfs1(dfs1, 0, -1);
        dfs2(dfs2, 0, -1);
        head[0] = 0;
        for (int u : ord) {
            for (int v : adj[u]) {
                if (v != par[u]) {
                    if (v == ch[u]) {
                        head[v] = head[u];
                    } else {
                        head[v] = v;
                    }
                }
            }
        }
    }

    bool is_anc(int u, int v) { return tl[u] <= tl[v] && tr[u] >= tr[v]; }

    int get_anc(int u, int x) {
        for (int i = anc[0].size() - 1; i >= 0; --i) {
            if (u != -1 && (x >> i & 1)) {
                u = anc[u][i];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (is_anc(u, v)) {
            return u;
        }
        for (int i = anc[0].size() - 1; i >= 0; --i) {
            if (anc[u][i] != -1 && !is_anc(anc[u][i], v)) {
                u = anc[u][i];
            }
        }
        return par[u];
    }
};

void solve() {
    int lft = 150;
    auto query = [&](int u) {
        std::cout << "? " << u + 1 << std::endl;
        lft--;
        int res;
        std::cin >> res;
        return res;
    };
    int n;
    std::cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        tree.add_edge(u, v);
    }
    tree.init();
    std::vector<int> vis(n);
    auto fill_vis = [&](auto &self, int u) {
        if (vis[u]) {
            return;
        }
        vis[u] = 1;
        for (int v : tree.adj[u]) {
            if (v != tree.par[u]) {
                self(self, v);
            }
        }
    };
    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(),
              [&](int i, int j) { return tree.dep[i] < tree.dep[j]; });
    for (int i = n - 1; i >= 0; i--) {
        int u = ord[i];
        if (vis[u]) {
            continue;
        }
        int v = u;
        for (int _ = 0; _ < (lft - 1) / 2 - 1; _++) {
            if (v == 0) {
                break;
            }
            v = tree.par[v];
        }
        if (!query(v)) {
            fill_vis(fill_vis, v);
            continue;
        }
        int x = tree.ord.back();
        int m = tree.dep[u] - tree.dep[v] + 1;
        for (int _ = 0; _ < m; _++) {
            if (query(x)) {
                std::cout << "! " << x + 1 << std::endl;
                return;
            }
            if (!query(v)) {
                int y = tree.par[v];
                if (y != -1) {
                    y = tree.par[y];
                }
                if (y == -1) {
                    y = 0;
                }
                std::cout << "! " << y + 1 << std::endl;
                return;
            }
        }
        std::cout << "! 1" << std::endl;
        return;
    }
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
