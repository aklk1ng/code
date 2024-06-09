#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n || (p[i - 1] < p[i]) != (p[i] < p[i + 1])) {
            ans.push_back(p[i]);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &e : ans) {
        std::cout << e << " \n"[e == ans.back()];
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
