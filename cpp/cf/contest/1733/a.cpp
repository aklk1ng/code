#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i % k] = std::max(a[i % k], x);
    }

    std::cout << std::accumulate(a.begin(), a.end(), 0LL) << '\n';
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
