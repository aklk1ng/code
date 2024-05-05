#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> b(n + 1);
    int bal = n;
    b[0] = bal;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '+') {
            bal++;
        } else {
            bal--;
        }
        b[i] = bal;
        for (int j = 0; j < i; j++) {
            if (b[j] >= b[i] && (b[j] - b[i]) % 3 == 0) {
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
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
