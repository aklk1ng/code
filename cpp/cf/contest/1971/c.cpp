#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::string s;
    for (int i = 1; i <= 12; i++) {
        if (i == a || i == b) {
            s += 'a';
        }
        if (i == c || i == d) {
            s += 'b';
        }
    }
    std::cout << (s == "abab" || s == "baba" ? "YES" : "NO") << '\n';
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
