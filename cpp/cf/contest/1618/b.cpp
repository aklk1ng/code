#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    bool ok = true;
    for (int i = 0; i < n - 3; i++) {
        if (s[i][1] != s[i + 1][0]) {
            s.push_back(i + 1, s[i][1] + s[i + 1][0]);
            ok = false;
            break;
        }
    }
    if (ok) {
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
