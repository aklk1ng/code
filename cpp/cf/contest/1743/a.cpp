#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto fac = [&](int num) {
        int res = 1;
        for (int i = 2; i <= num; i++) {
            res *= i;
        }
        return res;
    };
    auto cal = [&](int num, int k) { return fac(num) / fac(k) / fac(num - k); };
    std::cout << cal(10 - n, 2) * cal(4, 2) << '\n';
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
