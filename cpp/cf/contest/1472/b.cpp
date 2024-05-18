#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        if (c == 1) {
            cnt1++;
        } else {
            cnt2++;
        }
    }

    if ((cnt1 + 2 * cnt2) % 2) {
        std::cout << "NO\n";
    } else {
        int sum = (cnt1 + 2 * cnt2) / 2;
        if (sum % 2 == 0 || (sum % 2 && cnt1)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
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
