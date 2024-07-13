#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    for (int i = 0; i < 5; i++) {
        a[0]++;
        std::sort(a.begin(), a.end());
    }
    std::cout << a[0] * a[1] * a[2] << '\n';
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
