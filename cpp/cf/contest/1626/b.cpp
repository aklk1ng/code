#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = s[i] - '0';
    }
    n = x.size();
    bool ok = false;
    for (int i = n - 2; i >= 0; i--) {
        if (x[i] + x[i + 1] >= 10) {
            x[i + 1] += x[i] - 10;
            x[i] = 1;
            ok = true;
            break;
        }
    }
    if (!ok) {
        x[1] += x[0];
        x.erase(x.begin());
    }
    for (int i = 0; i < x.size(); i++) {
        std::cout << char(x[i] + '0');
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
