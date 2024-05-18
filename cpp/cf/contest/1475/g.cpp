#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e5 + 7;

std::vector<int> dp(N), cnt(N);

void solve() {
    int n;
    std::cin >> n;

    std::fill(dp.begin(), dp.end(), 0);
    std::fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; i++) {
        dp[i] += cnt[i];
        for (int j = 2 * i; j < N; j += i) {
            dp[j] = std::max(dp[j], dp[i]);
        }
    }
    std::cout << (n - *std::max_element(dp.begin(), dp.end())) << '\n';
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
