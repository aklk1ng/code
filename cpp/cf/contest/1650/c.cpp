#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct point {
    int w, pos, id;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<point> p(m);
    for (int i = 0; i < m; i++) {
        std::cin >> p[i].pos >> p[i].w;
        p[i].id = i + 1;
    }

    std::sort(p.begin(), p.end(), [](point a, point b) { return a.w < b.w; });
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (i < 2 * n) {
            sum += p[i].w;
        } else {
            p.pop_back();
        }
    }
    std::sort(p.begin(), p.end(),
              [](point a, point b) { return a.pos < b.pos; });
    std::cout << sum << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << p[i].id << ' ' << p[2 * n - i - 1].id << '\n';
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
