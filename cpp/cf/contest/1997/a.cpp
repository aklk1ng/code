#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int idx = -1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            idx = i;
        }
    }
    if (idx == -1) {
        if (s.back() == 'a') {
            std::cout << s + 'b' << '\n';
        } else {
            std::cout << s + 'a' << '\n';
        }
    } else {
        std::string t = "a";
        if (s[idx] == 'a') {
            t = 'b';
        }
        std::cout << s.substr(0, idx + 1) + t + s.substr(idx + 1) << '\n';
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
