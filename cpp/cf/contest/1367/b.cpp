#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x % 2 != i % 2) {
            if (i % 2 == 0) {
                a++;
            } else {
                b++;
            }
        }
    }
    std::cout << (a != b ? -1 : a) << '\n';
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
