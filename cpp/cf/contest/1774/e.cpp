#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 5;
int t[N * 2], nxt[N * 2], cnt, h[N];
int n, d;

void add(int x, int y) {
    t[++cnt] = y;
    nxt[cnt] = h[x];
    h[x] = cnt;
}

int a[N], b[N];
bool f[2][N];

void dfs1(int x, int fa, int dis) {
    a[dis] = x;
    if (dis > d) {
        b[x] = a[dis - d];
    } else {
        b[x] = 1;
    }
    for (int i = h[x]; i; i = nxt[i]) {
        if (t[i] == fa) {
            continue;
        }
        dfs1(t[i], x, dis + 1);
    }
}

void dfs2(int x, int fa, int tp) {
    bool u = 0;
    for (int i = h[x]; i; i = nxt[i]) {
        if (t[i] == fa) {
            continue;
        }
        dfs2(t[i], x, tp);
        u |= f[tp][t[i]];
    }
    f[tp][x] |= u;
}

void solve() {
    std::cin >> n >> d;
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }

    dfs1(1, 0, 1);
    for (int i = 0; i <= 1; i++) {
        int num;
        std::cin >> num;
        for (int j = 1; j <= num; j++) {
            int x;
            std::cin >> x;
            f[i][x] = 1;
            f[i ^ 1][b[x]] = 1;
        }
    }
    for (int i = 0; i <= 1; i++) {
        dfs2(1, 0, i);
    }
    int ans = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 2; j <= n; j++) {
            if (f[i][j]) {
                ans += 2;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
