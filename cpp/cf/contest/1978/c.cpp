#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    ll k, mx_s = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        mx_s += std::abs(n - 1 - i - i);
    }
    if (k % 2 || k > mx_s) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::vector<int> p(n);
        k /= 2;
        std::iota(p.begin(), p.end(), 0);
        for (int i = 0; k > 0; i++) {
            if (k >= n - 1 - 2 * i) {
                std::swap(p[i], p[n - 1 - i]);
                k -= n - 1 - 2 * i;
            } else {
                std::swap(p[i], p[i + k]);
                k = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << p[i] + 1 << " \n"[i == n - 1];
        }
    }
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
