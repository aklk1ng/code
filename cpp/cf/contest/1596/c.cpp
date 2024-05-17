#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    char ch;
    std::cin >> ch;
    std::string s;
    std::cin >> s;

    std::vector<int> ans;
    bool ok = true;
    for (auto &c : s) {
        if (c != ch) {
            ok = false;
        }
    }

    if (!ok) {
        for (int i = 1; i <= n; i++) {
            ok = true;
            for (int j = i; j <= n; j++) {
                ok &= (s[j - 1] == ch);
                j += i - 1;
            }
            if (ok) {
                ans.push_back(i);
                break;
            }
        }
        if (!ok) {
            ans.push_back(n);
            ans.push_back(n - 1);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &e : ans) {
        std::cout << e << " \n"[e == ans.back()];
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
