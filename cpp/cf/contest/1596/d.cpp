#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::vector<std::pair<ll, ll>>> adj;
std::vector<int> color(200005), ch(2);
bool ok;

void dfs(int idx) {
    ch[color[idx]]++;
    for (auto x : adj[idx]) {
        if (color[x.first] == -1) {
            color[x.first] = color[idx] ^ x.second;
            dfs(x.first);
        } else if (color[x.first] != (color[idx] ^ x.second)) {
            ok = false;
        }
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    adj.assign(n + 5, {});
    color.assign(n + 5, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::string c;
        std::cin >> a >> b >> c;
        if (c == "crewmate") {
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        } else {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }

    int ans = 0;
    ok = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1 ){
            color[i] = 0;
            ch[0] = ch[1] = 0;
            dfs(i);
            ans += std::max(ch[0], ch[1]);
        }
    }
    std::cout << (ok ? ans : -1) << '\n';
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
