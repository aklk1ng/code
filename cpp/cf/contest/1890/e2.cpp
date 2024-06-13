#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e5 + 23;
const int INF = 1e9;

void chkmax(int &x, int y) { x = std::max(x, y); }

struct Interval {
    int l, r;
} I[N];

bool cmp(int x, int y) { return I[x].l > I[y].l; }

std::vector<int> add[N], del[N];
int n, m, k, ban[N];

int st[21][N][18], lg[N];

int query(int d, int l, int r) {
    int len = lg[r - l + 1];
    return std::max(st[d][l][len], st[d][r - (1 << len) + 1][len]);
}

void change(int d, int p, int val) {
    chkmax(st[d][p][0], val);
    for (int i = 1; p - (1 << i) + 1 >= 0; ++i) {
        st[d][p - (1 << i) + 1][i] =
            std::max(st[d][p - (1 << i) + 1][i - 1],
                     st[d][p - (1 << (i - 1)) + 1][i - 1]);
    }
}

void init() {
    lg[0] = -1;
    for (int i = 1; i <= n + 1; ++i) {
        lg[i] = lg[i - 1] + ((i & -i) == i);
    }
    for (int i = 1; i <= m; ++i) {
        ban[i] = false;
    }
    for (int i = 1; i <= n + 1; ++i) {
        add[i].clear();
        del[i].clear();
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int _k = 0; _k < 18; ++_k) {
                st[i][j][_k] = -INF;
            }}}
}

void solve() {
    std::cin >> n >> m >> k;
    init();
    for (int i = 1; i <= m; ++i) {
        int l, r;
        std::cin >> l >> r;
        I[i] = (Interval){l, r};
        add[l].push_back(i);
        del[r + 1].push_back(i);
    }

    std::vector<int> cur, tmp;

    change(0, 0, 0);

    int uncover = 0, ans = 0;
    int cnti = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto j : add[i]) {
            cur.push_back(j);
            ++cnti;
        }

        for (auto j : del[i]) {
            ban[j] = true;
            --cnti;
        }

        if (cnti > k) {
            for (int j = 0; j <= k; ++j) {
                change(j, i, -INF);
            }
            continue;
        }

        tmp.clear();
        for (auto j : cur) {
            if (!ban[j]) {
                tmp.push_back(j);
            }
        }
        cur = tmp;
        std::sort(cur.begin(), cur.end(), cmp);

        if (cur.empty()) {
            for (int j = 0; j <= k; ++j) {
                change(j, i, -INF);
            }
            ++uncover;
            continue;
        }

        if (I[cur[0]].l <= i - 1) {
            for (int g = 0; g <= k; ++g) {
                int z = query(g, I[cur[0]].l, i - 1);
                chkmax(ans, z + 1);
                change(g, i, z + 1);
            }
        } else {
            for (int g = 0; g <= k; ++g) {
                change(g, i, -INF);
            }
        }
        int cp = I[cur[0]].l - 1;

        for (int j = 0; j < cur.size(); ++j) {
            if (j + 1 != cur.size() && I[cur[j]].l == I[cur[j + 1]].l) {
                continue;
            }
            int np = (j + 1 == cur.size() ? 0 : I[cur[j + 1]].l);
            for (int g = j + 1; g <= k; ++g) {
                int z = query(g - (j + 1), np, cp);
                chkmax(ans, z + 1);
                change(g, i, z + 1);
            }
            cp = np - 1;
        }
    }
    std::cout <<  ans + uncover << '\n';
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
