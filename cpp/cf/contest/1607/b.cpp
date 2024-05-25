#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll x0, n;
    std::cin >> x0 >> n;

    ll d;
    switch (n % 4) {
    case 0:
        d = 0;
        break;
    case 1:
        d = n;
        break;
    case 2:
        d = -1;
        break;
    case 3:
        d = -n - 1;
    }
    std::cout << (x0 % 2 ? x0 + d : x0 - d) << '\n';
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
