#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> f(ll x) {
    std::vector<int> res;
    if (x == 2) {
        res.push_back(0);
    } else if (x & 1) {
        res = f(x - 1);
        res.push_back(*std::min_element(res.begin(), res.end()) - 1);
    } else {
        res = f(x / 2);
        res.push_back(*std::max_element(res.begin(), res.end()) + 1);
    }
    return res;
}

void solve() {
    ll x;
    std::cin >> x;
    auto ans = f(x);
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
