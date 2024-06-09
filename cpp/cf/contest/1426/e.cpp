#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        std::cin >> b[i];
    }

    int ans = INT_MAX;
    std::vector<std::pair<int, int>> ord;
    ord.push_back({0, 0});
    ord.push_back({0, 2});
    ord.push_back({1, 1});
    ord.push_back({1, 0});
    ord.push_back({2, 2});
    ord.push_back({2, 1});
    std::sort(ord.begin(), ord.end());
    do {
        std::vector<int> a1 = a, b1 = b;
        for (int i = 0; i < ord.size(); i++) {
            int cnt = std::min(a1[ord[i].first], b1[ord[i].second]);
            a1[ord[i].first] -= cnt;
            b1[ord[i].second] -= cnt;
        }
        int cur = std::min(a1[0], b1[1]) + std::min(a1[1], b1[2]) +
                  std::min(a1[2], b1[0]);
        ans = std::min(ans, cur);
    } while (std::next_permutation(ord.begin(), ord.end()));
    int ans2 =
        std::min(a[0], b[1]) + std::min(a[1], b[2]) + std::min(a[2], b[0]);
    std::cout << ans << ' ' << ans2 << '\n';
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
