#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::string go(std::string t) {
    while (t.back() == '0') {
        t.pop_back();
    }
    std::reverse(t.begin(), t.end());
    return t;
}

std::string to_bin(ll x) {
    if (x == 0) {
        return "";
    } else {
        std::string s = to_bin(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}

void solve() {
    ll x, y;
    std::cin >> x >> y;

    std::set<std::string> vis;
    std::queue<std::string> q;
    q.push(to_bin(x));
    vis.insert(to_bin(x));
    while (!q.empty()) {
        auto k = q.front();
        q.pop();
        if (k.size() > 100) {
            continue;
        }
        for (int i = 0; i < 2; i++) {
            auto k2 = go(k + std::string(1, char('0' + i)));
            if (!vis.count(k2)) {
                vis.insert(k2);
                q.push(k2);
            }
        }
    }

    std::cout << (vis.count(to_bin(y)) ? "YES" : "NO") << '\n';
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
