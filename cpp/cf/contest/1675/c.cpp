#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    std::vector<bool> a(n + 1);
    a[0] = true;
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] && (s[i] == '1' || s[i] == '?');
    }
    std::vector<bool> b(n + 1);
    b[0] = true;
    for (int i = n - 1; i >= 0; i--) {
        b[n - i] = b[n - i - 1] && (s[i] == '0' || s[i] == '?');
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && b[n - i - 1]) {
            ans++;
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
