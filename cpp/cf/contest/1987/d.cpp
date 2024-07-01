#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    std::map<int, int> cnt;
    while (n--) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    for (auto &[k, v] : cnt) {
        a.push_back(v);
    }
    n = a.size();
    std::vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::vector<int> tmp = dp;
        for (int k = 1; k <= n; k++) {
            int nv = dp[k - 1] + a[i - 1];
            if (nv <= i - k) {
                tmp[k] = std::min(tmp[k], nv);
            }
        }
        dp = tmp;
    }
    int ans = n;
    while (dp[ans] >= 1e9) {
        ans--;
    }
    std::cout << n - ans << '\n';
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
