#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int INF = 2e9;

inline int add(int a, int b) { return (a + b >= 9 ? a + b - 9 : a + b); }

inline int sub(int a, int b) { return (a < b ? a + 9 - b : a - b); }

inline int mul(int a, int b) { return a * b % 9; }

void solve() {
    std::string s;
    std::cin >> s;
    int n, m;
    std::cin >> n >> m;

    std::vector<int> D[9], ps(2e5 + 5);
    auto build = [&]() {
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            ps[i + 1] = ps[i] + (s[i] - '0');
        }
        for (int i = 0; i + n <= sz; ++i) {
            D[(ps[i + n] - ps[i]) % 9].push_back(i);
        }
    };
    auto cal = [&](int l, int r, int k) -> std::pair<int, int> {
        int x = (ps[r] - ps[l]) % 9;
        std::pair<int, int> res{INF, INF};
        for (int a = 0; a < 9; ++a) {
            int b = sub(k, mul(a, x));
            if (D[a].empty() || D[b].empty()) {
                continue;
            }
            if (a != b) {
                res = std::min(res, {D[a].front(), D[b].front()});
            } else if (D[a].size() >= 2) {
                res = std::min(res, {D[a].front(), D[a][1]});
            }
        }
        if (res == std::make_pair(INF, INF)) {
            return {-2, -2};
        }
        return res;
    };
    build();
    for (int i = 0; i < m; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--;
        auto [ans1, ans2] = cal(l, r, k);
        std::cout << ++ans1 << ' ' << ++ans2 << '\n';
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
