#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int ask(int a, int b) {
    std::cout << '?' << " " << a << " " << a + b << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve() {
    int r = 0;
    for (int i = 1; i <= 30; i++) {
        int ans = ask((1 << (i - 1)) - r, (1 << i));
        if (ans == (1 << i)) {
            r += (1 << (i - 1));
        }
    }
    std::cout << '!' << " " << r << std::endl;
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
