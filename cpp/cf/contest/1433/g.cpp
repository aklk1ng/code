#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int n;
std::vector<std::vector<int>> d;
std::vector<std::vector<std::pair<int, int>>> g;

void dijkstra(int s, std::vector<int> &d) {
    d = std::vector<int>(n, INT_MAX);
    d[s] = 0;
    std::set<std::pair<int, int>> st;
    st.insert({d[s], s});
    while (!st.empty()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto [to, w] : g[v]) {
            if (d[to] > d[v] + w) {
                auto it = st.find({d[to], to});
                if (it != st.end()) {
                    st.erase(it);
                }
                d[to] = d[v] + w;
                st.insert({d[to], to});
            }
        }
    }
}

void solve() {
    int m, k;
    std::cin >> n >> m >> k;
    g = std::vector<std::vector<std::pair<int, int>>>(n);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        --x, --y;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    std::vector<std::pair<int, int>> r(k);
    for (auto &[a, b] : r) {
        std::cin >> a >> b;
        --a, --b;
    }

    d = std::vector<std::vector<int>>(n);
    for (int v = 0; v < n; ++v) {
        dijkstra(v, d[v]);
    }

    int ans = INT_MAX;
    for (int v = 0; v < n; ++v) {
        for (auto [to, w] : g[v]) {
            int cur = 0;
            for (auto [a, b] : r) {
                cur +=
                    std::min({d[a][b], d[a][v] + d[to][b], d[a][to] + d[v][b]});
            }
            ans = std::min(ans, cur);
        }
    }

    std::cout << ans << '\n';
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
