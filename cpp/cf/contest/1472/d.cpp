#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::sort(v.rbegin(), v.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (v[i] % 2 == 0) {
                ans += v[i];
            }
        } else {
            if (v[i] % 2) {
                ans -= v[i];
            }
        }
    }
    if (ans == 0) {
        std::cout << "Tie\n";
    } else if (ans > 0) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
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
