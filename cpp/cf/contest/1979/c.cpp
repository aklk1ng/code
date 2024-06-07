#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }

    ll z = 1;
    for (int i = 0; i < n; i++) {
        z = z * k[i] / std::__gcd(z, (ll)k[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += z / k[i];
    }
    if (sum < z) {
        for (int i = 0; i < n; i++) {
            std::cout << z / k[i] << " \n"[i == n - 1];
        }
    } else {
        std::cout << "-1\n";
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
