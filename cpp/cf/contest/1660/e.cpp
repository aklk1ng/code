#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int cnt1 = 0;
    std::vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0, k = (n - i) % n; j < n;
             j++, k = (k + 1 == n ? 0 : k + 1)) {
            if (s[j] == '1') {
                cnt1++;
                cnt[k]++;
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < cnt.size(); i++) {
        ans = std::min(ans, cnt1 - cnt[i] + (n - cnt[i]));
    }
    std::cout << ans << '\n';
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
