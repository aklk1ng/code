#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g1, g2;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        g1.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        g2.push_back(s);
    }

    std::vector<int> sr1(m), sr2(m), sc1(n), sc2(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sr1[j] += g1[i][j] - '0';
            sr1[j] %= 3;
            sr2[j] += g2[i][j] - '0';
            sr2[j] %= 3;
            sc1[i] += g1[i][j] - '0';
            sc1[i] %= 3;
            sc2[i] += g2[i][j] - '0';
            sc2[i] %= 3;
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= sc1[i] == sc2[i];
    }
    for (int i = 0; i < m; i++) {
        ok &= sr1[i] == sr2[i];
    }
    std::cout << (ok ? "Yes" : "No") << '\n';
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
