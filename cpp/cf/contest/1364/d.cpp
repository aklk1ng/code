#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int pos[100005];
std::vector<int> v[100005], col[100005], s;
std::vector<int> cyc;

bool dfs(int node) {
    pos[node] = s.size();
    col[pos[node] % 2].push_back(node);
    s.push_back(node);
    int low = -1;
    for (int u : v[node]) {
        if (pos[u] != -1 && pos[node] - pos[u] > 1) {
            low = std::max(low, pos[u]);
        }
    }
    if (low != -1) {
        for (int i = low; i <= pos[node]; i++) {
            cyc.push_back(s[i]);
        }
        return true;
    }
    for (int u : v[node]) {
        if (pos[u] == -1) {
            if (dfs(u)) {
                return true;
            }
        }
    }
    s.pop_back();
    return 0;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(pos, -1, sizeof(pos));
    dfs(1);
    if (cyc.empty()) {
        if (col[0].size() < col[1].size()) {
            swap(col[0], col[1]);
        }
        std::cout << "1\n";
        for (int i = 0; i < (k + 1) / 2; i++) {
            std::cout << col[0][i] << ' ';
        }
    } else {
        if (cyc.size() <= k) {
            std::cout << "2\n" << cyc.size() << '\n';
            for (int i : cyc) {
                std::cout << i << ' ';
            }
        } else {
            std::cout << "1\n";
            for (int i = 0; i < (k + 1) / 2; i++) {
                std::cout << cyc[2 * i] << ' ';
            }
        }
    }
    std::cout << '\n';
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
