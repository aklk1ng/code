#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll ask(int a, int b) {
    std::cout << "? " << a << ' ' << b << std::endl;
    ll x;
    std::cin >> x;
    return x;
}

void solve() {
    for (int i = 2; i <= 26; i++) {
        ll x = ask(1, i);
        ll y = ask(i, 1);
        if (x == -1) {
            std::cout << "! " << i - 1 << std::endl;
            return;
        }
        if (x != y) {
            std::cout << "! " << x + y << std::endl;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
