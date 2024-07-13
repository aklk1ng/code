#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    int mx = *std::max_element(a.begin(), a.end());
    std::cout << 2 * (n - mx) - k + 1 << '\n';
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
