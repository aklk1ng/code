#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int s;
    std::cin >> s;

    std::string ans;
    for (int d = 9; d >= 1; d--) {
        if (s >= d) {
            ans = char('0' + d) + ans;
            s -= d;
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
