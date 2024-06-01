#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
std::vector<std::vector<int>> sl;
std::vector<int> nearest;

int count(int v, int dist, int p = -1) {
    bool children = true;
    int s = 0;
    for (int u : sl[v]) {
        if (u == p) {
            continue;
        }
        int c = count(u, dist + 1, v);
        if (c < 0) {
            children = false;
        }
        nearest[v] = std::min(nearest[v], nearest[u] + 1);
        s += c;
    }
    if (nearest[v] <= dist) {
        return 1;
    }
    if (s == 0 || !children) {
        return -1;
    }
    return s;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    sl.assign(n, std::vector<int>(0));
    nearest.assign(n, n);
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        x--;
        nearest[x] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        sl[u].push_back(v);
        sl[v].push_back(u);
    }

    std::cout << count(0, 0) << '\n';
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
