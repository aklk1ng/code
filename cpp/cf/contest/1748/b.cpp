#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> fre(10);
        int d = 0, mx = 0;
        for (int j = i; j < n && (++fre[s[j] - '0'] <= 10); j++) {
            mx = std::max(mx, fre[s[j] - '0']);
            if (fre[s[j] - '0'] == 1) {
                d++;
            }
            if (d >= mx) {
                ans++;
            }
        }
    }
    std::cout << ans << '\n';
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
