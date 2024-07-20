#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct node {
    node *l, *r;
    ll sumc, sumr;

    node() : l(NULL), r(NULL), sumc(0), sumr(0) {}

    node(node *l, node *r, ll sumc, ll sumr)
        : l(l), r(r), sumc(sumc), sumr(sumr) {}
};

node *build(int l, int r, std::vector<int> &c) {
    if (l == r - 1) {
        return new node(NULL, NULL, c[l], 0);
    }
    int m = (l + r) / 2;
    node *nw = new node();
    nw->l = build(l, m, c);
    nw->r = build(m, r, c);
    nw->sumc = nw->l->sumc + nw->r->sumc;
    return nw;
}

node *upd(node *v, int l, int r, int pos, int val) {
    if (l == r - 1) {
        return new node(NULL, NULL, 0, val);
    }
    int m = (l + r) / 2;
    node *nw = new node(v->l, v->r, 0, 0);
    if (pos < m) {
        nw->l = upd(v->l, l, m, pos, val);
    } else {
        nw->r = upd(v->r, m, r, pos, val);
    }
    nw->sumc = nw->l->sumc + nw->r->sumc;
    nw->sumr = nw->l->sumr + nw->r->sumr;
    return nw;
}

ll getsum(node *v, int mult) { return v->sumc + v->sumr * mult; }

int trav(node *v, int l, int r, int L, int R, ll &lft, int mult) {
    if (L >= R) {
        return 0;
    }
    if (l == L && r == R && lft - getsum(v, mult) >= 0) {
        lft -= getsum(v, mult);
        return r - l;
    }
    if (l == r - 1) {
        return 0;
    }
    int m = (l + r) / 2;
    int cnt = trav(v->l, l, m, L, std::min(m, R), lft, mult);
    if (cnt == std::max(0, std::min(m, R) - L)) {
        cnt += trav(v->r, m, r, std::max(m, L), R, lft, mult);
    }
    return cnt;
}

struct seg {
    int l, r, lst, cur;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> c(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i] >> r[i];
    }

    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(),
              [&](int x, int y) { return c[x] / r[x] > c[y] / r[y]; });
    std::vector<int> vals;
    for (int i : ord) {
        vals.push_back(c[i] / r[i]);
    }
    std::vector<node *> root(1, build(0, n, c));
    for (int i : ord) {
        root.push_back(upd(root.back(), 0, n, i, r[i]));
    }
    std::vector<seg> st;
    for (int i = n - 1; i >= 0; --i) {
        st.push_back({i, i + 1, 0, c[i]});
    }

    ll ans = 0;
    int q;
    std::cin >> q;
    while (q--) {
        int t;
        ll h;
        std::cin >> t >> h;
        while (!st.empty()) {
            auto it = st.back();
            st.pop_back();
            if (it.r - it.l == 1) {
                it.cur = std::min((ll)c[it.l],
                                  it.cur + (t - it.lst) * 1ll * r[it.l]);
                if (it.cur <= h) {
                    h -= it.cur;
                } else {
                    st.push_back({it.l, it.r, t, int(it.cur - h)});
                    h = 0;
                }
            } else {
                int mx =
                    vals.rend() -
                    std::lower_bound(vals.rbegin(), vals.rend(), t - it.lst);
                int res =
                    it.l + trav(root[mx], 0, n, it.l, it.r, h, t - it.lst);
                assert(res <= it.r);
                if (res != it.r) {
                    if (it.r - res > 1) {
                        st.push_back({res + 1, it.r, it.lst, 0});
                    }
                    int nw = std::min((ll)c[res], r[res] * 1ll * (t - it.lst));
                    assert(nw - h > 0);
                    st.push_back({res, res + 1, t, int(nw - h)});
                    h = 0;
                }
            }
            if (h == 0) {
                break;
            }
        }
        if (st.empty()) {
            st.push_back({0, n, t, 0});
        } else if (st.back().l != 0) {
            st.push_back({0, st.back().l, t, 0});
        }
        ans += h;
    }

    std::cout << ans << '\n';
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
