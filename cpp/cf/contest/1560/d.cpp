#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::string> ts;

void init() {
    for (ll i = 1; i <= 2e18; i *= 2) {
        ts.push_back(std::to_string(i));
    }
}

void solve() {
    std::string n;
    std::cin >> n;

    auto cal = [&](std::string s, std::string t) -> int {
        int tp = 0, sp = 0, take = 0;

        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                take++;
                tp++;
            }
            sp++;
        }
        return s.length() - take + t.length() - take;
    };
    int ans = n.length() + 1;
    for (auto &e : ts) {
        ans = std::min(ans, cal(n, e));
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    init();
    while (T--) {
        solve();
    }

    return 0;
}
