#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (idx < t.size()) {
                s[i] = t[idx++];
            } else {
                s[i] = 'a';
            }
        } else if (s[i] == t[idx]) {
            idx++;
        }
    }
    if (idx >= t.size()) {
        std::cout << "Yes\n" << s << '\n';
    } else {
        std::cout << "No\n";
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
