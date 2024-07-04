#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = '0' + s;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int ans = 0, i = 0;
    while (i <= n) {
        int mi = a[i], sm = a[i];
        int j = i + 1;
        while (j <= n && s[j] == '1') {
            mi = std::min(mi, a[j]);
            sm += a[j];
            j++;
        }
        ans += sm - mi;
        i = j;
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
