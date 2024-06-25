#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::cin.ignore();
    std::set<int> xs, ys;
    for (int i = 0; i < 3; i++) {
        int x, y;
        std::cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
    }

    if (xs.size() == 3 || ys.size() == 3) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
