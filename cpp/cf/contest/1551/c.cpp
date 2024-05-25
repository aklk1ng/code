#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> cnt(26);
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;

        int sz = -s.length();
        for (int j = 0; j < 26; j++) {
            cnt[j].push_back(sz);
        }
        for (auto &c : s) {
            cnt[c - 'a'].back() += 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        auto &b = cnt[i];
        std::sort(b.begin(), b.end());
        std::reverse(b.begin(), b.end());
        if (b[0] <= 0) {
            continue;
        }
        int sum = b[0];
        int j = 1;
        for (; j < n && sum > 0; j++) {
            sum += b[j];
        }
        if (sum <= 0) {
            j--;
        }
        if (j > ans) {
            ans = j;
        }
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
