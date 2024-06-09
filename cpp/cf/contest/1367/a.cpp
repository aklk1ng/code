#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string b;
    std::cin >> b;

    std::string a = b.substr(0, 2);
    for (int i = 3; i < b.size(); i += 2) {
        a += b[i];
    }
    std::cout << a << '\n';
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
