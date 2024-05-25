#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    int l = 1, r = n;
    int div = 0;
    while (l + 1 != r) {
        int m = (l + r) / 2;
        std::cout << "+ " << n - m << std::endl;
        int d;
        std::cin >> d;
        if (d > div) {
            l = m;
        } else {
            r = m;
        }
        l = (l + n - m) % n;
        r = (r + n - m) % n;
        if (!r) {
            r = n;
        }
        div = d;
    }
    std::cout << "! " << div * n + l << std::endl;
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
