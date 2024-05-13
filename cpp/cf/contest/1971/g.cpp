#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, std::priority_queue<int>> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i] >> 2].push(-a[i]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << -mp[a[i] >> 2].top() << " \n"[i == n - 1];
        mp[a[i] >> 2].pop();
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
