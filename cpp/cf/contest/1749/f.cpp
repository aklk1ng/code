#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = int(2e5) + 55;
const int LOG = 18;

int n;
std::vector<int> g[N];
int p[LOG][N];
int tin[N], tout[N], T = 0;

void build(int v, int pr) {
    tin[v] = T++;
    p[0][v] = pr;
    for (int pw = 1; pw < LOG; pw++) {
        p[pw][v] = p[pw - 1][p[pw - 1][v]];
    }

    for (int to : g[v]) {
        if (to == pr) {
            continue;
        }
        build(to, v);
    }
    tout[v] = T;
}

bool inside(int l, int v) { return tin[l] <= tin[v] && tout[v] <= tout[l]; }

int lca(int u, int v) {
    if (inside(u, v))
        return u;
    if (inside(v, u))
        return v;

    for (int pw = LOG - 1; pw >= 0; pw--) {
        if (!inside(p[pw][u], v))
            u = p[pw][u];
    }
    return p[0][u];
}

const int D = 21;

struct Fenwick {
    int n;
    std::vector<int> F;

    void init(int nn) {
        n = nn;
        F.assign(n, 0);
    }

    void add(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            F[pos] += val;
        }
    }

    int sum(int pos) {
        int ans = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            ans += F[pos];
        }
        return ans;
    }

    int getSum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

struct DS {
    Fenwick f;

    void init(int _n) { f.init(_n); }

    void addPath(int v, int l, int k) {
        f.add(tin[v], +k);
        f.add(tin[l], -k);
    }

    int getVertex(int v) { return f.getSum(tin[v], tout[v]); }

    void addVertex(int v, int k) {
        f.add(tin[v], +k);
        if (p[0][v] != v) {
            f.add(tin[p[0][v]], -k);
        }
    }
};

DS t[D];

void solve() {
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    for (int i = 0; i < D; i++) {
        g[n - 1 + i].push_back(n + i);
        g[n + i].push_back(n - 1 + i);
    }
    int root = n + D - 1;

    build(root, root);
    for (int i = 0; i < D; i++) {
        t[i].init(root + 1);
    }

    int m;
    std::cin >> m;
    for (int _ = 0; _ < m; _++) {
        int tp;
        std::cin >> tp;
        if (tp == 1) {
            int v;
            std::cin >> v;
            v--;

            int ans = 0;
            for (int i = 0, cur = v; i < D; i++, cur = p[0][cur]) {
                ans += t[i].getVertex(cur);
            }
            std::cout << ans << '\n';
        } else {
            assert(tp == 2);

            int u, v, k, d;
            std::cin >> u >> v >> k >> d;
            u--, v--;

            int l = lca(u, v);

            if (u != l) {
                t[d].addPath(u, l, k);
            }
            if (v != l) {
                t[d].addPath(v, l, k);
            }

            for (int i = 0; i <= d; i++, l = p[0][l]) {
                t[d - i].addVertex(l, k);
                if (d - i > 0) {
                    t[d - i - 1].addVertex(l, k);
                }
            }
        }
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
