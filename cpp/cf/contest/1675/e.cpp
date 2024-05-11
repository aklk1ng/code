#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    char mn = 'a';
    for (int i = 0; i < n; i++) {
        if (s[i] > mn) {
            if (s[i] - 'a' > k) {
                k -= mn - 'a';
                int to = s[i] - k;
                for (auto c = s[i]; c > to; c--) {
                    for (auto &e : s) {
                        if (e == c) {
                            e = char(c - 1);
                        }
                    }
                }
                break;
            } else {
                if (mn < s[i]) {
                    mn = s[i];
                }
            }
        }
    }
    for (auto &e : s) {
        if (e <= mn) {
            e = 'a';
        }
    }
    std::cout << s << '\n';
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
