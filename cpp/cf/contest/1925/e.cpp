#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const long long N = 3e5 + 5;

struct ap {
    ll base, dif;
};

ap add(ap a, ap b) {
    ap res;
    res.base = a.base + b.base;
    res.dif = a.dif + b.dif;
    return res;
}

ll convert(ap a, ll n) {
    ll res = (n * a.base);
    res += ((n * (n - 1)) / 2ll) * a.dif;
    return res;
}

ll st[4 * N], cost[N];
ap lazy[4 * N];
ap zero = {0, 0};

void propogate(ll node, ll l, ll r) {
    st[node] += convert(lazy[node], r - l + 1);
    if (l != r) {
        lazy[node * 2 + 1] = add(lazy[node * 2 + 1], lazy[node]);
        ll mid = (l + r) / 2;
        ll rig = (r - mid);
        lazy[node].base += (rig * lazy[node].dif);
        lazy[node * 2] = add(lazy[node * 2], lazy[node]);
    }
    lazy[node] = zero;
}

void build(ll node, ll l, ll r) {
    if (l == r) {
        st[node] = cost[l];
        lazy[node] = zero;
        return;
    }
    ll mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    st[node] = (st[node * 2] + st[node * 2 + 1]);
    lazy[node] = zero;
    return;
}

void update(ll node, ll l, ll r, ll x, ll y, ap val) {
    if (lazy[node].base != 0 || lazy[node].dif != 0) {
        propogate(node, l, r);
    }
    if (y < x || x > r || y < l) {
        return;
    }
    if (l >= x && r <= y) {
        st[node] += convert(val, r - l + 1);
        if (l != r) {
            lazy[node * 2 + 1] = add(lazy[node * 2 + 1], val);
            ll mid = (l + r) / 2;
            ll rig = (r - mid);
            val.base += (rig * val.dif);
            lazy[node * 2] = add(lazy[node * 2], val);
        }
        return;
    }
    ll mid = (l + r) / 2;
    update(node * 2 + 1, mid + 1, r, x, y, val);
    if (y > mid) {
        ll rig = (std::min(y, r) - mid);
        val.base += (rig * val.dif);
    }
    update(node * 2, l, mid, x, y, val);
    st[node] = st[node * 2] + st[node * 2 + 1];
    return;
}

ll query(ll node, ll l, ll r, ll x, ll y) {
    if (lazy[node].base != 0 || lazy[node].dif != 0) {
        propogate(node, l, r);
    }
    if (y < x || y < l || x > r) {
        return 0;
    }
    if (l >= x && r <= y) {
        return st[node];
    }
    ll mid = (l + r) / 2;
    return query(node * 2, l, mid, x, y) +
           query(node * 2 + 1, mid + 1, r, x, y);
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::set<int> harbours;
    ll X[m], V[n + 1];
    for (int i = 0; i < m; i++) {
        std::cin >> X[i];
        harbours.insert(X[i]);
    }
    for (int i = 0; i < m; i++) {
        int v;
        std::cin >> v;
        cost[X[i]] = v;
        V[X[i]] = v;
    }
    for (int i = 1; i <= n; i++) {
        if (cost[i] == 0)
            cost[i] = cost[i - 1];
    }
    ll dist = 0;
    for (int i = n; i > 0; i--) {
        if (harbours.find(i) != harbours.end()) {
            dist = 0;
        } else {
            dist++;
        }
        cost[i] *= dist;
    }
    build(1, 1, n);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v;
            V[x] = v;
            auto it = harbours.lower_bound(x);
            int nxt = (*it);
            it--;
            int prev = (*it);
            ap lef = {(V[prev] * (x - nxt)), 0};
            ap rig = {0, V[x] - V[prev]};
            update(1, 1, n, prev + 1, x, lef);
            update(1, 1, n, x + 1, nxt, rig);
            harbours.insert(x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << query(1, 1, n, l, r) << '\n';
        }
    }
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
