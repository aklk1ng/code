#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x;
    std::cin >> x;

    std::vector<int> ans;
    int sum = 0, lst = 9;
    while (sum < x && lst > 0) {
        ans.push_back(std::min(x - sum, lst));
        sum += lst;
        lst--;
    }
    if (sum < x) {
        std::cout << "-1\n";
        return;
    }
    std::reverse(ans.begin(), ans.end());
    for (auto &e : ans) {
        std::cout << e;
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
