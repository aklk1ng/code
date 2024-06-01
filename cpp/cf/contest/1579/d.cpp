#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    auto cmp = [](std::pair<int, int> const &x, std::pair<int, int> const &y) {
        return x > y;
    };
    std::set<std::pair<int, int>, decltype(cmp)> a(cmp);
    std::vector<std::pair<int, int>> answer;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        if (ai > 0) {
            a.emplace(ai, i + 1);
        }
    }

    while (a.size() > 1) {
        auto p1 = *a.begin();
        a.erase(a.begin());
        auto p2 = *a.begin();
        a.erase(a.begin());
        answer.emplace_back(p1.second, p2.second);
        if (p1.first > 1) {
            a.emplace(p1.first - 1, p1.second);
        }
        if (p2.first > 1) {
            a.emplace(p2.first - 1, p2.second);
        }
    }
    std::cout << answer.size() << '\n';
    for (auto &p : answer) {
        std::cout << p.first << ' ' << p.second << '\n';
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
