#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> cnt(2);
    for (auto &c : s) {
        cnt[c - '0']++;
    }
    for (int i = 0; i <= n; i++) {
        if (i == s.size() || cnt[1 - (s[i] - '0')] == 0) {
            std::cout << s.size() - i << '\n';
            break;
        }
        cnt[1 - (s[i] - '0')]--;
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
