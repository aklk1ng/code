#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int maxn = 1000100;

int n, lsh[maxn], tot, fa[maxn];
std::pair<int, int> b[maxn];

struct node {
    int l, r, x;
} a[maxn];

struct edg {
    int u, v, d;

    edg(int a = 0, int b = 0, int c = 0) : u(a), v(b), d(c) {}
} E[maxn];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

inline bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        fa[x] = y;
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    tot = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].l >> a[i].r >> a[i].x;
        lsh[++tot] = a[i].l;
        lsh[++tot] = (++a[i].r);
    }
    int m = 0;
    std::sort(lsh + 1, lsh + tot + 1);
    tot = std::unique(lsh + 1, lsh + tot + 1) - lsh - 1;
    for (int i = 1; i <= n; ++i) {
        a[i].l = std::lower_bound(lsh + 1, lsh + tot + 1, a[i].l) - lsh;
        a[i].r = std::lower_bound(lsh + 1, lsh + tot + 1, a[i].r) - lsh;
        b[++m] = std::make_pair(a[i].l, i);
        b[++m] = std::make_pair(a[i].r, -i);
    }
    std::set<std::pair<int, int>> S;
    std::sort(b + 1, b + m + 1);
    int tt = 0;
    for (int i = 1; i <= m; ++i) {
        int j = b[i].second;
        if (j > 0) {
            auto it = S.insert(std::make_pair(a[j].x, j)).first;
            if (it != S.begin()) {
                int k = std::prev(it)->second;
                E[++tt] = edg(j, k, std::abs(a[j].x - a[k].x));
            }
            if (std::next(it) != S.end()) {
                int k = std::next(it)->second;
                E[++tt] = edg(j, k, std::abs(a[j].x - a[k].x));
            }
        } else {
            j = -j;
            S.erase(std::make_pair(a[j].x, j));
        }
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    std::sort(E + 1, E + tt + 1,
              [&](const edg &a, const edg &b) { return a.d < b.d; });
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= tt; ++i) {
        if (merge(E[i].u, E[i].v)) {
            ++cnt;
            ans += E[i].d;
        }
    }
    std::cout << (cnt == n - 1 ? ans : -1) << '\n';
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
