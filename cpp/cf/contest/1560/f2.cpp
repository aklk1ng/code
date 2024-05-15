#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string n;
    int k;
    std::cin >> n >> k;

    while (true) {
        std::set<char> s;
        for (auto &c : n) {
            s.insert(c);
        }
        if (s.size() <= k) {
            std::cout << n << '\n';
            return;
        }

        s.clear();
        int p = 0;
        while (true) {
            s.insert(n[p]);
            if (s.size() > k) {
                while (n[p] == '9') {
                    p--;
                }
                n[p]++;
                for (int i = p + 1; i < n.size(); i++) {
                    n[i] = '0';
                }
                break;
            }
            p++;
        }
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
