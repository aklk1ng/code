#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cout << i <<  " \n"[i == n];
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
