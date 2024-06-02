#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool good(int i, int d) { return i % d == 0 && i % (1ll * d * d) != 0; }

void solve() {
    int x, d;
    std::cin >> x >> d;

    std::map<std::pair<int, int>, int> dp;
    dp[{x, 1}] = 1;
    int ans = 0;
    std::vector<int> del;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (good(i, d)) {
                del.push_back(i);
            }
            if (x != i * i && good(x / i, d)) {
                del.push_back(x / i);
            }
        }
    }
    while (!dp.empty()) {
        auto z = *dp.rbegin();
        if (z.first.first == 1) {
            ans += z.second;
        }
        for (auto &i : del) {
            if (z.first.first % i == 0 && i >= z.first.second) {
                dp[{z.first.first / i, i}] =
                    std::min(dp[{z.first.first / i, i}] + z.second, 2);
            }
        }
        dp.erase(z.first);
    }
    std::cout << (ans == 1 ? "NO" : "YES") << '\n';
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
