#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int calc(const std::string &s, char c) {
    if (s.size() == 1) {
        return s[0] != c;
    }
    int mid = s.size() / 2;
    int cntl = calc(std::string(s.begin(), s.begin() + mid), c + 1);
    cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
    int cntr = calc(std::string(s.begin() + mid, s.end()), c + 1);
    cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
    return std::min(cntl, cntr);
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::cout << calc(s, 'a') << '\n';
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
