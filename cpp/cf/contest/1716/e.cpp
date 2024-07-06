#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int K = 18;

struct node {
    ll sum, pref, suff, ans;

    node(const node &l, const node &r) {
        sum = l.sum + r.sum;
        pref = std::max(l.pref, l.sum + r.pref);
        suff = std::max(r.suff, r.sum + l.suff);
        ans = std::max(std::max(l.ans, r.ans), l.suff + r.pref);
    }

    node(int x) {
        sum = x;
        pref = suff = ans = std::max(x, 0);
    }

    node() {};
};

int a[1 << K];
std::vector<node> tree[2 << K];

void build(int v, int l, int r) {
    tree[v].resize(r - l);
    if (l == r - 1) {
        tree[v][0] = node(a[l]);
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        for (int i = 0; i < m - l; i++) {
            tree[v][i] = node(tree[v * 2 + 1][i], tree[v * 2 + 2][i]);
            tree[v][i + (m - l)] = node(tree[v * 2 + 2][i], tree[v * 2 + 1][i]);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    int m = (1 << n);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    build(0, 0, m);
    int q;
    std::cin >> q;
    int cur = 0;
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        cur ^= (1 << x);
        std::cout << tree[0][cur].ans << '\n';
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
