#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct trie {
    int l, c;
    std::vector<std::array<int, 2>> node;
    std::vector<int> cnt;

    trie(int l, int max_members)
        : l(l), c(0), node((l + 2) * max_members + 3),
          cnt((l + 2) * max_members + 3) {}

    void add(int x) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            ++cnt[cur];
        }
    }

    void remove(int x) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            --cnt[cur];
        }
    }

    int find_max(int x) {
        int cur = 0, ans = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (node[cur][!has_bit] && cnt[node[cur][!has_bit]]) {
                ans += 1 << i;
                cur = node[cur][!has_bit];
            } else {
                cur = node[cur][has_bit];
            }
        }
        return ans;
    }
};

const int N = 2e5 + 2;
int x[N];
std::bitset<N> dp;
std::vector<std::array<int, 2>> e[N];

void dfs(int c, int p) {
    for (auto [i, w] : e[c]) {
        if (i == p) {
            continue;
        }
        dp[i] = !dp[c];
        x[i] = x[c] ^ w;
        dfs(i, c);
    }
}

void solve() {
    int n, m, gx = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1, u, v, w; i < n; ++i) {
        std::cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    dfs(1, 0);
    std::vector<trie> t(2, trie(30, n));
    for (int i = 1; i <= n; ++i) {
        t[dp[i]].add(x[i]);
    }
    while (m--) {
        char c;
        std::cin >> c;
        if (c == '^') {
            int y;
            std::cin >> y;
            gx ^= y;
        } else {
            int a, b;
            std::cin >> a >> b;
            t[dp[a]].remove(x[a]);
            int same_group = t[dp[a]].find_max(x[a] ^ b);
            int diff_group = t[1 - dp[a]].find_max(x[a] ^ b ^ gx);
            t[dp[a]].add(x[a]);
            std::cout << std::max(same_group, diff_group) << ' ';
        }
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
