#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    auto ca = a.back();
    auto cb = b.back();
    if (ca == cb) {
        if (a.size() == b.size()) {
            std::cout << '=';
        } else if (ca == 'S') {
            std::cout << (a.size() < b.size() ? '>' : '<');
        } else {
            std::cout << (a.size() < b.size() ? '<' : '>');
        }
    } else {
        std::cout << (ca < cb ? '>' : '<');
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
