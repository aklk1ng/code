#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string a;
    std::cin >> a;

    std::vector<int> cnt(7);
    int ans = 0;
    for (auto c : a) {
        cnt[c - 'A']++;
    }
    for (int i = 0; i < 7; i++) {
        ans += std::max(0, m - cnt[i]);
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
