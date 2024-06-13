#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int h, n;
    std::cin >> h >> n;
    std::vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::set<std::pair<ll, int>> S;
    for (int i = 0; i < n; i++) {
        S.insert({1, i});
    }
    ll ans = 1;
    while (h > 0) {
        auto [turn, i] = *S.begin();
        S.erase(S.begin());
        ans = turn;
        h -= a[i];
        S.insert({turn + c[i], i});
    }
    std::cout << ans << "\n";
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
