#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 300043;

typedef std::array<int, 2> vec;
typedef std::array<vec, 2> mat;

mat operator*(const mat &a, const mat &b) {
    mat c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][k] = (a[i][j] * 1ll * b[j][k] + c[i][k]) % mod;
            }
        }
    }
    return c;
}

mat ZERO = {vec({3, 0}), vec({1, 2})};
mat ONE = {vec({1, 2}), vec({1, 2})};

mat t[4 * N];

void recalc(int v) { t[v] = t[v * 2 + 1] * t[v * 2 + 2]; }

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v] = ZERO;
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        recalc(v);
    }
}

void upd(int v, int l, int r, int pos, int val) {
    if (l == r - 1) {
        if (val == 0) {
            t[v] = ZERO;
        } else {
            t[v] = ONE;
        }
    } else {
        int m = (l + r) / 2;
        if (pos < m) {
            upd(v * 2 + 1, l, m, pos, val);
        } else {
            upd(v * 2 + 2, m, r, pos, val);
        }
        recalc(v);
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> v(N);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        v[l].push_back(std::make_pair(1, i));
        v[r + 1].push_back(std::make_pair(0, i));
    }

    build(0, 0, n - 1);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i <= 300000; i++) {
        for (auto x : v[i]) {
            if (x.second == 0) {
                cur = x.first;
            } else {
                upd(0, 0, n - 1, x.second - 1, x.first);
            }
        }
        ans = (ans + t[0][cur][1]) % mod;
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
