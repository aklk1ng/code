#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void calc(int l, int r, int k) {
    if (l == r) {
        std::cout << "! " << l << std::endl;
        return;
    }
    int m = (l + r) / 2;
    std::cout << "? " << l << " " << m << std::endl;
    int sum;
    std::cin >> sum;
    if ((m - l + 1) - sum >= k) {
        calc(l, m, k);
    } else {
        calc(m + 1, r, k - (m - l + 1) + sum);
    }
}

void solve() {
    int n, t, k;
    std::cin >> n >> t >> k;
    calc(1, n, k);
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
