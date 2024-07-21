#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1000010;

int T, n, q;
ll a[N];

struct INFO {
    int ans, l, r;
    ll sum;
    std::vector<int> lpos, rpos;
    std::vector<ll> lsum, rsum;
};

struct nod {
    INFO info;
    nod *lc, *rc;
};

struct Segtree {
    nod *root;

    Segtree() { build(&root, 1, n); }

    void newnod(nod **p, int l, int r) {
        *p = new nod;
        (*p)->info.l = l;
        (*p)->info.r = r;
        (*p)->info.sum = (*p)->info.ans = 0;
        (*p)->lc = (*p)->rc = NULL;
    }

    INFO merge_info(INFO x, INFO y) {
        INFO z;
        z.l = x.l;
        z.r = y.r;
        z.sum = x.sum + y.sum;
        z.ans = std::max(x.ans, y.ans);
        int px = (int)x.lpos.size() - 1, py = 0;
        ll mx = 0;
        while (1) {
            int len = 0;
            ll sum = 0;
            if (px < 0) {
                sum += x.sum;
                len += (x.r - x.l + 1);
            } else {
                sum += x.lsum[px] - a[x.lpos[px]];
                len += (x.r - x.lpos[px]);
            }
            if (py < y.rpos.size()) {
                sum += y.rsum[py] - a[y.rpos[py]];
                len += (y.rpos[py] - y.l);
            } else {
                sum += y.sum;
                len += (y.r - y.l + 1);
            }
            if (sum > 2 * mx) {
                z.ans = std::max(z.ans, len);
            }
            if (px < 0 && py >= y.rpos.size()) {
                break;
            } else if (px < 0) {
                mx = std::max(mx, a[y.rpos[py]]), py++;
            } else if (py >= y.rpos.size()) {
                mx = std::max(mx, a[x.lpos[px]]), px--;
            } else if (a[x.lpos[px]] < a[y.rpos[py]]) {
                mx = std::max(mx, a[x.lpos[px]]), px--;
            } else {
                mx = std::max(mx, a[y.rpos[py]]), py++;
            }
        }
        if (z.ans < 3) {
            z.ans = -1;
        }
        for (int i = 0; i < x.lpos.size(); i++) {
            if (2 * a[x.lpos[i]] >= x.lsum[i] + y.sum) {
                z.lpos.push_back(x.lpos[i]),
                    z.lsum.push_back(x.lsum[i] + y.sum);
            }
        }
        for (int i = 0; i < y.lpos.size(); i++) {
            z.lpos.push_back(y.lpos[i]), z.lsum.push_back(y.lsum[i]);
        }
        for (int i = 0; i < x.rpos.size(); i++) {
            z.rpos.push_back(x.rpos[i]), z.rsum.push_back(x.rsum[i]);
        }
        for (int i = 0; i < y.rpos.size(); i++) {
            if (2 * a[y.rpos[i]] >= y.rsum[i] + x.sum) {
                z.rpos.push_back(y.rpos[i]),
                    z.rsum.push_back(y.rsum[i] + x.sum);
            }
        }
        return z;
    }

    void build(nod **p, int L, int R) {
        newnod(p, L, R);
        if (L == R) {
            (*p)->info.sum = a[L];
            (*p)->info.ans = -1;
            (*p)->info.lpos.push_back(L);
            (*p)->info.rpos.push_back(L);
            (*p)->info.lsum.push_back(a[L]);
            (*p)->info.rsum.push_back(a[L]);
            return;
        }
        int M = (L + R) >> 1;
        build(&(*p)->lc, L, M);
        build(&(*p)->rc, M + 1, R);
        (*p)->info = merge_info((*p)->lc->info, (*p)->rc->info);
    }

    void modify(int pos, ll val) { _modify(root, pos, val); }

    void _modify(nod *p, int pos, ll val) {
        if (p->info.l == p->info.r) {
            p->info.sum = val;
            p->info.lpos[0] = pos;
            p->info.rpos[0] = pos;
            p->info.lsum[0] = val;
            p->info.rsum[0] = val;
            return;
        }
        int M = (p->info.l + p->info.r) >> 1;
        if (pos <= M) {
            _modify(p->lc, pos, val);
        } else {
            _modify(p->rc, pos, val);
        }
        p->info = merge_info(p->lc->info, p->rc->info);
    }

    ll getans(int L, int R) { return _getans(root, L, R).ans; }

    INFO _getans(nod *p, int L, int R) {
        if (p->info.l == L && p->info.r == R) {
            return p->info;
        }
        int M = (p->info.l + p->info.r) >> 1;
        if (R <= M) {
            return _getans(p->lc, L, R);
        } else if (L > M) {
            return _getans(p->rc, L, R);
        } else {
            return merge_info(_getans(p->lc, L, M), _getans(p->rc, M + 1, R));
        }
    }
};

void solve() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    Segtree TR;
    for (int i = 1; i <= q; i++) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int l, r;
            std::cin >> l >> r;
            std::cout << TR.getans(l, r) << '\n';
        } else {
            int p;
            ll x;
            std::cin >> p >> x;
            a[p] = x;
            TR.modify(p, x);
        }
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
