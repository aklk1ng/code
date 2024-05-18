#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool check(std::vector<std::vector<int>> a,
           std::vector<std::vector<int>> const &b) {
    int n = (int)a.size();
    for (int j = 0; j < n; j++) {
        if (a[0][j] != b[0][j]) {
            for (int i = 0; i < n; i++) {
                a[i][j] ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int need_xor = (a[i][0] ^ b[i][0]);
        for (int j = 1; j < n; j++) {
            if (need_xor != (a[i][j] ^ b[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<int>(n)), b(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < 2; i++) {
        if (check(a, b)) {
            std::cout << "YES\n";
            return;
        }
        for (int j = 0; j < n; j++) {
            a[0][j] ^= 1;
        }
    }
    std::cout << "NO\n";
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
