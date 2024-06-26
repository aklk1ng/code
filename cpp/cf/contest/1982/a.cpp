#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int la, lb;
    std::cin >> la >> lb;
    int ra, rb;
    std::cin >> ra >> rb;

    if (la > lb) {
        std::swap(la, lb);
        std::swap(ra, rb);
    }
    if (la < lb && rb < ra) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
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
