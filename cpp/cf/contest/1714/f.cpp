#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> d[i];
    }

    int sum = std::accumulate(d.begin(), d.end(), 0);
    if (sum % 2 == 0) {
        std::vector<int> w(3);
        for (int i = 0; i < 3; i++) {
            w[i] = sum / 2 - d[(i + 1) % 3];
        }
        std::vector<int> sw(w.begin(), w.end());
        std::sort(sw.begin(), sw.end());
        if (sw[0] >= 0 && sw[1] >= 1) {
            std::vector<std::pair<int, int>> edges;
            int num = 3;
            int center;
            if (sw[0] == 0) {
                center = std::min_element(w.begin(), w.end()) - w.begin();
            } else {
                center = num++;
            }
            for (int i = 0; i < 3; i++) {
                int old = center;
                for (int j = 0; j < w[i] - 1; j++) {
                    edges.push_back({old, num});
                    old = num++;
                }
                if (w[i] > 0) {
                    edges.push_back({old, i});
                }
            }
            if (num <= n) {
                while (num < n) {
                    edges.push_back({center, num++});
                }
                std::cout << "YES\n";
                for (auto &[u, v] : edges) {
                    std::cout << u + 1 << ' ' << v + 1 << '\n';
                }
                return;
            }
        }
    }
    std::cout << "NO\n";
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
