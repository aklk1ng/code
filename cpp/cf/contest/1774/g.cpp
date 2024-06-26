#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

using tp = std::tuple<int, int, int>;
const int sgn[] = {1, 998244352};
const int N = 200005;

int x[N], y[N];
std::vector<tp> V;
bool del[N];
int fa[20][N];
int m, q;

void solve() {
    std::cin >> m >> q;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x[i] >> y[i];
        V.emplace_back(y[i], -x[i], i);
    }
    std::sort(V.begin(), V.end());
    int mxl = 0;
    for (auto [y, x, i] : V) {
        if (-x <= mxl) {
            del[i] = true;
        }
        mxl = std::max(mxl, -x);
    }
    V.clear();
    x[m + 1] = y[m + 1] = 1e9 + 1;
    for (int i = 1; i <= m + 1; ++i) {
        if (!del[i]) {
            V.emplace_back(x[i], y[i], i);
        }
    }
    std::sort(V.begin(), V.end());
    for (auto [x, y, id] : V) {
        int t =
            std::get<2>(*std::lower_bound(V.begin(), V.end(), tp{y + 1, 0, 0}));
        fa[0][id] = t;
    }
    fa[0][m + 1] = m + 1;
    for (int k = 1; k <= 17; ++k) {
        for (int i = 1; i <= m + 1; ++i) {
            fa[k][i] = fa[k - 1][fa[k - 1][i]];
        }
    }
    for (int i = 1; i <= q; ++i) {
        int l, r;
        std::cin >> l >> r;
        int u = std::lower_bound(V.begin(), V.end(), tp{l, 0, 0}) - V.begin(),
            v = u + 1;
        u = std::get<2>(V[u]);
        if (x[u] != l || y[u] > r) {
            std::cout << "0\n";
            continue;
        }
        if (y[u] == r) {
            std::cout << "998244352\n";
            continue;
        }
        v = std::get<2>(V[v]);
        if (y[v] > r || x[v] > y[u]) {
            std::cout << "0\n";
            continue;
        }
        int numu = 0, numv = 0;
        for (int i = 17; i >= 0; --i) {
            if (y[fa[i][u]] <= r) {
                u = fa[i][u];
                numu += !i;
            }
        }
        for (int i = 17; i >= 0; --i) {
            if (y[fa[i][v]] <= r) {
                v = fa[i][v];
                numv += !i;
            }
        }
        if (u == v || (y[u] != r && y[v] != r)) {
            std::cout << "0\n";
        } else {
            std::cout << sgn[numu ^ numv] << '\n';
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
