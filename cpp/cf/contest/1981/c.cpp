#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

inline std::vector<int> path(int x, int y) {
    std::vector<int> L, R;
    while (std::__lg(x) > std::__lg(y)) {
        L.push_back(x);
        x >>= 1;
    }
    while (std::__lg(y) > std::__lg(x)) {
        R.push_back(y);
        y >>= 1;
    }
    while (x != y) {
        L.push_back(x);
        R.push_back(y);
        x >>= 1;
        y >>= 1;
    }
    L.push_back(x);
    std::reverse(R.begin(), R.end());
    for (int x : R) {
        L.push_back(x);
    }
    return L;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), v;
    int L = -1, R = -1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] != -1) {
            if (L == -1) {
                L = i;
            }
            R = i;
            v.push_back(i);
        }
    }

    if (L == -1) {
        for (int i = 1; i <= n; i++) {
            std::cout << (i & 1) + 1 << " \n"[i == n];
        }
        return;
    }
    for (int i = L - 1; i; --i) {
        a[i] = (((L - i) & 1) ? a[L] * 2 : a[L]);
    }
    for (int i = R + 1; i <= n; ++i) {
        a[i] = (((i - R) & 1) ? a[R] * 2 : a[R]);
    }
    for (int _ = 1; _ < (int)v.size(); ++_) {
        int l = v[_ - 1], r = v[_];
        std::vector<int> p = path(a[l], a[r]);
        if (((int)p.size() & 1) != ((r - l + 1) & 1) ||
            r - l + 1 < (int)p.size()) {
            std::cout << "-1\n";
            return;
        }
        for (int i = 0; i < (int)p.size(); ++i) {
            a[l + i] = p[i];
        }
        for (int i = l + (int)p.size(), o = 1; i <= r; ++i, o ^= 1) {
            a[i] = (o ? a[i - 1] * 2 : a[i - 1] / 2);
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << " \n"[i == n];
    }
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
