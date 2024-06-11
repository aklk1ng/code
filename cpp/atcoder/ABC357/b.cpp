#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int lower = 0, upper = 0;
    for (auto &c : s) {
        (islower(c) ? lower : upper)++;
    }
    if (lower < upper) {
        for (auto &c : s) {
            if (islower(c)) {
                c = toupper(c);
            }
        }
    } else {
        for (auto &c : s) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
    }
    std::cout << s << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
