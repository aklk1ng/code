#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    std::map<int, int> cnt;
    int b = 0;
    cnt[b]++;
    ll ans = 0;
    for (auto &c : s) {
        b += c == '(' ? 1 : -1;
        ans += cnt[b];
        cnt[b]++;
        while (cnt.begin()->first * 2 < b) {
            cnt.erase(cnt.begin());
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
