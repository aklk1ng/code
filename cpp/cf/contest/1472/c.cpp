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

    std::vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i];
        int j = i + a[i];
        if (j < n) {
            dp[i] += dp[j];
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
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
