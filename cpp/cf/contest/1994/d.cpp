#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> pos(n);
    std::iota(pos.begin(), pos.end(), 0);
    std::vector<std::pair<int, int>> ans;
    for (int i = n - 1; i; i--) {
        std::vector<int> occ(i, -1);
        for (auto &j : pos) {
            if (occ[a[j] % i] != -1) {
                ans.emplace_back(j, occ[a[j] % i]);
                pos.erase(std::find(pos.begin(), pos.end(), j));
                break;
            }
            occ[a[j] % i] = j;
        }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << "Yes\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << ' ' << y + 1 << '\n';
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
