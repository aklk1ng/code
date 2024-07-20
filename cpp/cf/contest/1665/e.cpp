#include <bits/stdc++.h>
using ll = long long;
const int MAXK = 31;
std::vector<std::pair<int, int>> t;

std::pair<int, int> get(int v, int vl, int vr, int l, int r) {
    if (vl >= l && vr <= r) {
        return t[v];
    }
    if (r <= vl || l >= vr) {
        return std::make_pair(INT_MAX, INT_MAX);
    }
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
}

void mod(int v, int vl, int vr, int id, int val) {
    if (vr - vl == 1) {
        t[v] = std::make_pair(val, id);
        return;
    }
    int vm = (vl + vr) / 2;
    if (id < vm) {
        mod(2 * v + 1, vl, vm, id, val);
    } else {
        mod(2 * v + 2, vm, vr, id, val);
    }
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &c : a) {
        std::cin >> c;
    }
    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        mod(0, 0, n, i, a[i]);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        std::vector<std::pair<int, int>> b;
        for (int i = 0; i < std::min(r - l, MAXK); i++) {
            auto now = get(0, 0, n, l, r);
            b.push_back(now);
            mod(0, 0, n, now.second, INT_MAX);
        }
        int ans = (1LL << 31) - 1;
        for (int i = 0; i < (int)b.size(); i++) {
            for (int j = i + 1; j < (int)b.size(); j++) {
                ans = std::min(ans, b[i].first | b[j].first);
            }
        }
        for (auto &c : b) {
            mod(0, 0, n, c.second, c.first);
        }
        std::cout << ans << "\n";
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
