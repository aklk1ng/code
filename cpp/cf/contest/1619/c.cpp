#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll a, s;
    std::cin >> a >> s;

    std::vector<int> b;
    while (s) {
        int x = a % 10;
        int y = s % 10;
        if (x <= y) {
            b.emplace_back(y - x);
        } else {
            s /= 10;
            y += 10 * (s % 10);
            if (x < y && y >= 10 && y <= 19) {
                b.emplace_back(y - x);
            } else {
                std::cout << "-1\n";
                return;
            }
        }
        a /= 10;
        s /= 10;
    }
    if (a) {
        std::cout << "-1\n";
        return;
    }
    while (b.back() == 0) {
        b.pop_back();
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        std::cout << b[i];
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
