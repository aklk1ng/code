#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (auto &c : s) {
        cnt[c - 'a']++;
    }
    int pairs = 0, odd = 0;
    for (auto &e : cnt) {
        pairs += e / 2;
        odd += e % 2;
    }
    int ans = 2 * (pairs / k);
    odd += 2 * (pairs % k);
    if (odd >= k) {
        ans++;
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
