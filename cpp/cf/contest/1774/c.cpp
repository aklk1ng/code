#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> ps(2);
    for (int i = 1; i < n; i++) {
        ps[s[i - 1] - 48] = i;
        if (s[i - 1] == '0') {
            std::cout << ps[1] + 1 << " \n"[i == n - 1];
        } else {
            std::cout << ps[0] + 1 << " \n"[i == n - 1];
        }
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
