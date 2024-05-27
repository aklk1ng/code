#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    if (a[1] != a[2]) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n" << a[0] << ' ' << a[0] << ' ' << a[2] << '\n';
    }
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
