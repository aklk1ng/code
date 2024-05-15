#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int k;
    std::cin >> k;

    int a = 1, x = 1, i = 1;
    while (k >= x + a) {
        x += a;
        a += 2;
        i++;
    }
    int m = k - x + 1;
    if (m <= i) {
        std::cout << m << ' ' << i << '\n';
    } else {
        std::cout << i << ' ' << (i - (m - i)) << '\n';
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
