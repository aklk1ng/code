#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::vector<int>> t;
std::vector<int> p, h;

void init(int v) {
    for (int u : t[v])
        if (u != p[v]) {
            p[u] = v;
            h[u] = h[v] + 1;
            init(u);
        }
}

std::vector<int> get_path(int v, int u) {
    std::vector<int> l, r;
    while (v != u) {
        if (h[v] > h[u]) {
            l.push_back(v);
            v = p[v];
        } else {
            r.push_back(u);
            u = p[u];
        }
    }
    l.push_back(v);
    while (!r.empty()) {
        l.push_back(r.back());
        r.pop_back();
    }
    return l;
}

std::vector<std::vector<int>> g, tg;

void add_edge(int v, bool vx, int u, bool vy) {
    g[v * 2 + vx].push_back(u * 2 + vy);
    tg[u * 2 + vy].push_back(v * 2 + vx);
    g[u * 2 + !vy].push_back(v * 2 + !vx);
    tg[v * 2 + !vx].push_back(u * 2 + !vy);
}

std::vector<int> ord;
std::vector<char> used;

void ts(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            ts(u);
        }
    }
    ord.push_back(v);
}

std::vector<int> clr;
int cnt;

void dfs(int v) {
    clr[v] = cnt;
    for (int u : tg[v]) {
        if (clr[u] == -1) {
            dfs(u);
        }
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    t.resize(n);
    p.resize(n);
    h.resize(n);
    p[0] = -1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    init(0);
    std::vector<std::vector<int>> paths(m);
    std::vector<std::string> s(m);
    std::vector<std::pair<char, char>> opts(n, {-1, -1});
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> v >> u >> s[i];
        u--, v--;
        paths[i] = get_path(v, u);
        int k = s[i].size();
        for (int j = 0; j < k; j++) {
            opts[paths[i][j]] = {s[i][j], s[i][k - j - 1]};
        }
    }
    int mn = (n + m) * 2;
    g.resize(mn);
    tg.resize(mn);
    for (int i = 0; i < m; i++) {
        int k = s[i].size();
        for (int j = 0; j < k; j++) {
            int v = paths[i][j];
            char c = s[i][j], rc = s[i][k - j - 1];
            char d = opts[v].first, rd = opts[v].second;
            if (d != c) {
                add_edge(v, false, n + i, true);
            }
            if (d != rc) {
                add_edge(v, false, n + i, false);
            }
            if (rd != c) {
                add_edge(v, true, n + i, true);
            }
            if (rd != rc) {
                add_edge(v, true, n + i, false);
            }
        }
    }
    used.resize(mn);
    for (int i = 0; i < mn; i++) {
        if (!used[i]) {
            ts(i);
        }
    }
    clr.resize(mn, -1);
    std::reverse(ord.begin(), ord.end());
    for (auto &v : ord) {
        if (clr[v] == -1) {
            dfs(v);
            ++cnt;
        }
    }
    for (int i = 0; i < mn; i++) {
        if (clr[i] == clr[i ^ 1]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < 2 * n; i += 2) {
        if (opts[i / 2].first == -1) {
            std::cout << 'a';
        } else if (clr[i] > clr[i ^ 1]) {
            std::cout << opts[i / 2].first;
        } else {
            std::cout << opts[i / 2].second;
        }
    }
    std::cout << '\n';
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
