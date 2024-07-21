#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x, y;
    std::cin >> n >> x>> y;

    x--, y--;
    std::vector<int> a(n, 1);
    int e = -1;
    for (int i = x + 1; i < n; i++) {
        a[i] = e;
        e *= -1;
    }
    e = -1;
    for (int i = y - 1; i >= 0; i--) {
        a[i] = e;
        e *= -1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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
