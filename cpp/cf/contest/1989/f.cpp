#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct edge {
    int v, u;
};

std::vector<std::vector<int>> g, tg;
std::vector<int> ord;
std::vector<char> used;
std::vector<int> clr;

void ts(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            ts(u);
        }
    }
    ord.push_back(v);
}

void dfs(int v, int k) {
    clr[v] = k;
    for (int u : tg[v]) {
        if (clr[u] == -1) {
            dfs(u, k);
        }
    }
}

std::vector<ll> rk, p;
ll sum;
std::vector<ll *> where;
std::vector<ll> val;

ll cost(int x) { return x == 1 ? 0ll : x * 1ll * x; }

int getp(int a) { return a == p[a] ? a : getp(p[a]); }

void unite(int a, int b) {
    a = getp(a), b = getp(b);
    if (a == b) {
        return;
    }
    if (clr[a] != clr[b]) {
        return;
    }
    if (rk[a] < rk[b]) {
        std::swap(a, b);
    }
    where.push_back(&sum);
    val.push_back(sum);
    sum -= cost(rk[a]);
    sum -= cost(rk[b]);
    sum += cost(rk[a] + rk[b]);
    where.push_back(&rk[a]);
    val.push_back(rk[a]);
    rk[a] += rk[b];
    where.push_back(&p[b]);
    val.push_back(p[b]);
    p[b] = a;
}

std::vector<edge> e;
std::vector<ll> ans;

void calc(int l, int r, const std::vector<int> &cur) {
    if (l == r - 1) {
        ans.push_back(sum);
        return;
    }
    int m = (l + r) / 2;
    for (int i : cur) {
        if (i < m) {
            int v = getp(e[i].v), u = getp(e[i].u);
            for (int w : {v, u}) {
                if (used[w]) {
                    g[w].clear();
                    tg[w].clear();
                    clr[w] = -1;
                    used[w] = false;
                }
            }
            g[v].push_back(u);
            tg[u].push_back(v);
        }
    }
    ord.clear();
    for (int i : cur)
        if (i < m) {
            for (int v : {getp(e[i].v), getp(e[i].u)}) {
                if (!used[v]) {
                    ts(v);
                }
            }
        }
    std::reverse(ord.begin(), ord.end());
    int k = 0;
    for (int v : ord)
        if (clr[v] == -1) {
            dfs(v, k);
            ++k;
        }
    int tim = val.size();
    for (int i : cur) {
        if (i < m) {
            unite(e[i].v, e[i].u);
        }
    }
    std::vector<int> tol, tor;
    for (int i : cur) {
        if (i >= m) {
            tor.push_back(i);
        } else if (getp(e[i].v) == getp(e[i].u)) {
            tol.push_back(i);
        } else {
            tor.push_back(i);
        }
    }
    calc(m, r, tor);
    while (int(val.size()) > tim) {
        *where.back() = val.back();
        where.pop_back();
        val.pop_back();
    }
    calc(l, m, tol);
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    e.resize(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        char c;
        std::cin >> x >> y >> c;
        --x, --y;
        if (c == 'R') {
            e[i] = {y + n, x};
        } else {
            e[i] = {x, y + n};
        }
    }
    rk.resize(n + m, 1);
    p.resize(n + m);
    std::iota(p.begin(), p.end(), 0);
    used.resize(n + m, 0);
    clr.resize(n + m, -1);
    g.resize(n + m);
    tg.resize(n + m);
    std::vector<int> cur(q);
    std::iota(cur.begin(), cur.end(), 0);
    calc(0, q + 1, cur);
    ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    for (ll x : ans) {
        std::cout << x << '\n';
    }
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
