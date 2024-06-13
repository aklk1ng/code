#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 100005;
std::stack<int> s[N];
int re[N], st[N], vis[N], tp;

int dfs(int u) {
    if (re[u]) {
        return re[u];
    }
    if (s[u].empty()) {
        return u;
    }
    if (vis[u]) {
        st[tp + 1] = 0;
        while (st[tp + 1] != u) {
            s[st[tp]].pop();
            vis[st[tp]] = 0;
            --tp;
        }
        return dfs(u);
    }
    st[vis[u] = ++tp] = u;
    return dfs(s[u].top());
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        while (k--) {
            int c;
            std::cin >> c;
            s[i].push(c);
        }
    }
    for (int i = 1; i <= n; ++i) {
        tp = 0;
        int ok = dfs(i);
        for (int j = 1; j <= tp; ++j) {
            re[st[j]] = ok;
        }
        std::cout << ok << " \n"[i == n];
    }
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
