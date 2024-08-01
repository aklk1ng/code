#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    ll ans = 0;
    std::deque<int> d;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '_') {
            c = d.empty() ? '(' : ')';
        }
        if (c == ')') {
            ans += i - d.back();
            d.pop_back();
        } else {
            d.push_back(i);
        }
    }
    std::cout << ans << '\n';
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
