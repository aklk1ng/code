#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string ab;
    std::cin >> ab;

    bool ok = false;
    int n = ab.size();
    for (int i = 1; i < n; i++) {
        if (ab[i] != '0' &&
            std::stoi(ab.substr(0, i)) < std::stoi(ab.substr(i))) {
            std::cout << ab.substr(0, i) << ' ' << ab.substr(i) << '\n';
            ok = true;
            break;
        }
    }
    if (!ok) {
        std::cout << "-1\n";
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
