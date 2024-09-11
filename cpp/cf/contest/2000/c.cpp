#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    while (m--) {
        std::unordered_map<char, int> m1;
        std::unordered_map<int, char> m2;
        std::string s;
        std::cin >> s;

        if (s.length() != n) {
            std::cout << "No\n";
            continue;
        }

        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (m1.find(s[j]) == m1.end() && m2.find(a[j]) == m2.end()) {
                m1[s[j]] = a[j];
                m2[a[j]] = s[j];
            } else if ((m1.find(s[j]) != m1.end() && m1[s[j]] != a[j]) ||
                       (m2.find(a[j]) != m2.end() && m2[a[j]] != s[j])) {
                ok = false;
                break;
            }
        }
        std::cout << (ok ? "Yes" : "No") << '\n';
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
