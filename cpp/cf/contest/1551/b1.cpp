#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (auto &c : s) {
        cnt[c - 'a']++;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            cnt1++;
        } else if (cnt[i] > 0) {
            cnt2++;
        }
    }
    std::cout << cnt2 + cnt1 / 2 << '\n';
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
