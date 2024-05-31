#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mx = std::max_element(a.begin(), a.end()) - a.begin();
    int mi = std::min_element(a.begin(), a.end()) - a.begin();
    std::cout << std::min({std::max(mx, mi) + 1, (n - 1) - std::min(mx, mi) + 1,
                           (n - 1) - mx + mi + 2, (n - 1) - mi + mx + 2})
              << '\n';
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
