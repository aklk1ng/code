#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    int c1 = n / 3;
    int c2 = c1;
    if (n % 3 == 1) {
        c1++;
    } else if (n % 3 == 2) {
        c2++;
    }
    std::cout << c1 << ' ' << c2 << '\n';
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
