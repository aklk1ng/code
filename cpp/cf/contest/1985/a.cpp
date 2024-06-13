#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string a, b;
    std::cin >> a >> b;

    std::swap(a[0], b[0]);
    std::cout << a << ' ' << b << '\n';
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
