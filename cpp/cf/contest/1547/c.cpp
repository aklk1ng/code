#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int k, n, m;
    std::cin >> k >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int pos1 = 0, pos2 = 0;
    std::vector<int> ans;
    while (pos1 != n || pos2 != m) {
        if (pos1 != n && !a[pos1]) {
            ans.push_back(0);
            k++;
            pos1++;
        } else if (pos2 != m && !b[pos2]) {
            ans.push_back(0);
            k++;
            pos2++;
        } else if (pos1 != n && a[pos1] <= k) {
            ans.push_back(a[pos1++]);
        } else if (pos2 != m && b[pos2] <= k) {
            ans.push_back(b[pos2++]);
        } else {
            std::cout << "-1\n";
            return;
        }
    }
    for (auto &e : ans) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
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
