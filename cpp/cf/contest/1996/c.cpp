#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector pre1(n + 1, std::vector<int>(26)),
        pre2(n + 1, std::vector<int>(26));
    for (int i = 1; i <= n; i++) {
        char c;
        std::cin >> c;
        pre1[i][c - 'a']++;
        for (int j = 0; j < 26; j++) {
            pre1[i][j] += pre1[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        char c;
        std::cin >> c;
        pre2[i][c - 'a']++;
        for (int j = 0; j < 26; j++) {
            pre2[i][j] += pre2[i - 1][j];
        }
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int diff = 0;
        for (int c = 0; c < 26; c++) {
            diff += std::abs(pre1[r][c] - pre1[l - 1][c] - pre2[r][c] +
                             pre2[l - 1][c]);
        }
        std::cout << diff / 2 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
