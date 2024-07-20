#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 3043;

std::vector<int> g[2 * N];
int n;
int used[2 * N];

int choose2(int n) { return n * (n + 1) / 2; }

int count_ways(int L, int R, const std::vector<int> &forbidden) {
    if (L > R) {
        int ml = *std::min_element(forbidden.begin(), forbidden.end());
        int mr = *std::max_element(forbidden.begin(), forbidden.end());
        return choose2(ml) + choose2(mr - ml - 1) + choose2(n - 1 - mr);
    }
    int minl = 0;
    int maxl = L;
    int minr = R;
    int maxr = n - 1;
    for (auto x : forbidden) {
        if (L <= x && x <= R) {
            return 0;
        } else if (x < L) {
            minl = std::max(minl, x + 1);
        } else {
            maxr = std::min(maxr, x - 1);
        }
    }
    return (maxl - minl + 1) * (maxr - minr + 1);
}

std::vector<int> cur;

void dfs(int x) {
    if (used[x] == 1) {
        return;
    }
    used[x] = 1;
    cur.push_back(x);
    for (auto y : g[x]) {
        dfs(y);
    }
}

ll calc(const std::vector<int> &cycle) {
    int m = cycle.size();
    int k = m / 2;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int z = cycle[i];
        if (z >= n) {
            z -= n;
        }
        ans += choose2(n) * 1ll * (choose2(z) + 0ll + choose2(n - z - 1));
        int l = n - 1, r = 0, L = n - 1, R = 0;
        int pl = i, pr = i;
        for (int j = 0; j < k; j++) {
            for (auto x : std::vector<int>({cycle[pl], cycle[pr]})) {
                if (x < n) {
                    l = std::min(l, x);
                    r = std::max(r, x);
                } else {
                    L = std::min(L, x - n);
                    R = std::max(R, x - n);
                }
            }
            std::vector<int> f, F;
            pl--;
            if (pl < 0) {
                pl += m;
            }
            pr++;
            if (pr >= m) {
                pr -= m;
            }
            for (auto x : std::vector<int>({cycle[pl], cycle[pr]})) {
                if (x < n) {
                    f.push_back(x);
                } else {
                    F.push_back(x - n);
                }
            }
            ll add = count_ways(l, r, f) * 1ll * count_ways(L, R, F);
            ans += add;
        }
    }
    return ans;
}

void solve() {
    std::cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = n * 1ll * choose2(n) * 1ll * choose2(n) * 2ll;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        dfs(i);
        std::vector<int> cycle = cur;
        ans -= calc(cycle);
        cur = std::vector<int>();
    }
    std::cout << ans / 2 << '\n';
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
