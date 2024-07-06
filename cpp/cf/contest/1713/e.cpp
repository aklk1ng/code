#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 2e3 + 5;

int n, a[N][N];

int par[N];

int getPar(int u) {
    if (u < 0) {
        return -getPar(-u);
    }
    if (u == par[u]) {
        return u;
    }
    return par[u] = getPar(par[u]);
}

void join(int u, int v) {
    u = getPar(u);
    v = getPar(v);
    if (abs(u) != abs(v)) {
        if (u > 0) {
            par[u] = v;
        } else {
            par[-u] = -v;
        }
    }
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }

    std::iota(par + 1, par + n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] < a[j][i]) {
                join(i, j);
            }
            if (a[i][j] > a[j][i]) {
                join(i, -j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (getPar(i) < 0) {
            continue;
        }
        for (int j = 1; j <= n; j++) {
            std::swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
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
