#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string b;
    std::cin >> b;

    std::vector<int> cnt(26);
    for (auto &c : b) {
        cnt[c - 'a']++;
    }
    std::string t;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            t += char('a' + i);
        }
    }
    std::vector<int> mp(26);
    for (int i = 0; i < t.size(); i++) {
        mp[t[i] - 'a'] = t[t.size() - 1 - i] - 'a';
    }
    for (int i = 0; i < n; i++) {
        std::cout << char('a' + mp[b[i] - 'a']);
    }
    std::cout << '\n';
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
