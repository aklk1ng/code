#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::string normalize(const std::string &v) {
    int cnt = 0;
    while (cnt < v.size() && v[cnt] == '0') {
        cnt++;
    }
    if (cnt == v.size()) {
        return "0";
    }
    return v.substr(cnt, int(v.size()) - cnt);
}

std::string operator|(const std::string &a, const std::string &b) {
    int sz = std::max(a.size(), b.size());
    std::string ans(sz, '0');
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
            ans[i + sz - int(a.size())] = '1';
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '1') {
            ans[i + sz - int(b.size())] = '1';
        }
    }
    return normalize(ans);
}

bool better(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a > b;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    char buf[1000043];
    std::cin >> buf;
    s = buf;
    std::string ans = s | s;
    int pos1 = s.find("1");
    if (pos1 != std::string::npos) {
        int pos2 = s.find("0", pos1);
        if (pos2 != std::string::npos) {
            int cur = pos1;
            int not_needed = 0;
            while (true) {
                if (cur == n || (s[cur] == '1' && cur > pos2)) {
                    break;
                }
                std::string nw = s | s.substr(pos1, n - pos1 - not_needed);
                if (better(nw, ans)) {
                    ans = nw;
                }
                cur++;
                not_needed++;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
