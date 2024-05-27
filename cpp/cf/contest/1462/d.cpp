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

    int sum = std::accumulate(a.begin(), a.end(), 0);
    for (int i = n; i >= 1; i--) {
        if (sum % i == 0) {
            int need = sum / i, cur = 0;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                cur += a[j];
                if (cur > need) {
                    ok = false;
                    break;
                } else if (cur == need) {
                    cur = 0;
                }
            }
            if (ok) {
                std::cout << n - i << '\n';
                return;
            }
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
