#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int cntsrc[26];          // don't forget to memset it but not cnt
int *cnt = cntsrc - 'a'; // so cnt['a'] = cntsrc[0] and so on

std::pair<std::string, std::string> decrypt(std::string s) {
    std::string order;
    reverse(s.begin(), s.end());
    for (auto c : s) {
        if (!cnt[c]) {
            order.push_back(c);
        }
        cnt[c]++;
    }

    int m = order.length();
    int originalLength = 0;
    for (int i = 0; i < m; i++) {
        originalLength += cnt[order[i]] / (m - i);
    }

    std::reverse(order.begin(), order.end());
    return {std::string(s.rbegin(), s.rbegin() + originalLength), order};
}

std::string encrypt(std::pair<std::string, std::string> p) {
    std::string result = p.first;

    for (auto c : p.second) {
        std::string temp;
        for (auto d : p.first)
            if (d != c) {
                temp.push_back(d);
                result.push_back(d);
            }
        p.first = temp;
    }

    return result;
}

void solve() {
    std::string s;
    std::cin >> s;

    memset(cntsrc, 0, sizeof(cntsrc));

    auto ans = decrypt(s);
    auto check = encrypt(ans);

    if (check == s) {
        std::cout << ans.first << ' ' << ans.second << '\n';
    } else {
        std::cout << "-1\n";
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
