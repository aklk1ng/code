#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    int t = 0;
    if (n % 3 == 1) {
        t = 1;
    } else {
        t = 2;
    }
    int sum = 0;
    while (sum != n) {
        std::cout << t;
        sum += t;
        t = 3 - t;
    }
    std::cout << '\n';
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
