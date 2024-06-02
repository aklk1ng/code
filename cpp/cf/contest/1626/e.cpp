#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 300043;

std::vector<int> g[N];
int cnt[N];
int c[N];
std::vector<int> g2[N];
int par[N];
int used[N];

void dfs(int x, int p = -1) {
    par[x] = p;
    for (auto y : g[x]) {
        if (y != p) {
            dfs(y, x);
            cnt[x] += cnt[y];
        }
    }
    cnt[x] += c[x];
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        for (auto j : g[i]) {
            if (i == par[j]) {
                if (c[i] == 1 || cnt[0] - cnt[j] > 1) {
                    g2[i].push_back(j);
                }
            } else {
                if (c[i] == 1 || cnt[i] > 1) {
                    g2[i].push_back(j);
                }
            }
        }
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) {
            q.push(i);
            used[i] = 1;
        }
    }
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto y : g2[k])
            if (used[y] == 0) {
                used[y] = 1;
                q.push(y);
            }
    }
    for (int i = 0; i < n; i++) {
        std::cout << used[i] << " \n"[i == n - 1];
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
