#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2), d(n + 2, INT_MAX);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
    }

    std::set<int> l, cur;
    for (int i = 0; i < n + 2; i++) {
        l.insert(i);
        cur.insert(i);
    }
    for (int z = 0; z < n; z++) {
        std::set<int> del, t;
        for (auto &e : cur) {
            auto it = l.find(e);
            if (it == l.end()) {
                continue;
            }
            int pre = *std::prev(it);
            int nxt = *std::next(it);
            if (a[pre] + a[nxt] > d[e]) {
                del.insert(e);
                t.insert(pre);
                t.insert(nxt);
            }
        }
        std::cout << del.size() << ' ';
        for (auto &e : del) {
            l.erase(e);
        }
        cur = t;
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
