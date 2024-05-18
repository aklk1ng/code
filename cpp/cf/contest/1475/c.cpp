#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int A, B, K;
    std::cin >> A >> B >> K;
    std::vector<int> a(A), b(B);
    std::vector<std::pair<int, int>> edges(K);
    for (int i = 0; i < K; i++) {
        std::cin >> edges[i].first;
    }
    for (int i = 0; i < K; i++) {
        std::cin >> edges[i].second;
    }

    for (auto &[x, y] : edges) {
        x--, y--;
        a[x]++;
        b[y]++;
    }
    ll ans = 0;
    for (auto &[x, y] : edges) {
        ans += K - a[x] - b[y] + 1;
    }
    std::cout << ans / 2 << '\n';
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
