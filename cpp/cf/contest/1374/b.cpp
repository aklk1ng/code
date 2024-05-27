#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    int cnt2 = 0, cnt3 = 0;
    while (n % 2 == 0) {
        n /= 2;
        cnt2++;
    }
    while (n % 3 == 0) {
        n /= 3;
        cnt3++;
    }
    if (n == 1 && cnt2 <= cnt3) {
        std::cout << 2 * cnt3 - cnt2 << '\n';
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
