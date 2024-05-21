#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool ok = false;
    auto next = [&](int x) { return x + x % 10; };
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] % 5 == 0) {
            ok = true;
            a[i] = next(a[i]);
        }
    }

    if (ok) {
        std::cout << (*std::min_element(a.begin(), a.end()) ==
                              *std::max_element(a.begin(), a.end())
                          ? "YES"
                          : "NO")
                  << '\n';
    } else {
        bool flag1 = false, flag2 = false;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (x % 10 != 2) {
                x = next(x);
            }
            if (x % 20 == 2) {
                flag1 = true;
            } else {
                flag2 = true;
            }
        }
        std::cout << ((flag1 & flag2) ? "NO" : "YES") << '\n';
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
