#include <bits/stdc++.h>
using ll = long long;
#define int long long
const int mod = 998244353;

std::mt19937_64
    rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    int a, b;
    while (m--) {
        int k = rng();
        std::cin >> a >> b;
        v[a - 1] ^= k;
        v[b - 1] ^= k;
    }
    std::map<int, int> c;
    for (auto &e : v) {
        m = std::max(m, c[a ^= e]++);
    }
    std::cout << n - m - 1 << '\n';
}

int32_t main() {
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
