#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int A = 2e5 + 13;
const int N = 2e5 + 13;
const int B = 2000;
const int SQRTA = 500;
const int K = N / B + 113;

int val[N];
std::vector<int> g[N];
int sz[N];
int gr[N];
int leaf[N], group_root[N];
int par[N];
bool heavy[N];

int tin[N], tout[N], T = 0, mid[N];
int et[N];
int valet[N];

void dfs1(int v, int pr, int depth) {
    par[v] = pr;
    sz[v] = 1;

    int mx = -1;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (u != pr) {
            dfs1(u, v, depth + 1);
            sz[v] += sz[u];
            if (mx == -1 || sz[g[v][mx]] < sz[u])
                mx = i;
        }
    }

    if (mx != -1) {
        std::swap(g[v][mx], g[v][0]);
    }
}

void dfs2(int v) {
    et[T] = v;
    tin[v] = T++;

    for (int u : g[v]) {
        if (u != par[v]) {
            dfs2(u);
        }
    }

    tout[v] = T;
}

struct Query {
    int ind;
    int v, u;
    int lv, rv, lu, ru;
    int b;

    Query(){};
};

bool cmp(const Query &a, const Query &b) {
    if (a.b != b.b) {
        return a.b < b.b;
    } else {
        return a.lu < b.lu;
    }
}

int cnt[A];
int block_index[A];
int block_mx[A];
int block_cnt_of_cnt[A / SQRTA + 13][A];

inline void insert(int i) {
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]--;
    cnt[valet[i]]++;
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]++;
    if (cnt[valet[i]] > block_mx[block_index[valet[i]]]) {
        block_mx[block_index[valet[i]]]++;
    }
}

inline void erase(int i) {
    if (cnt[valet[i]] == block_mx[block_index[valet[i]]] &&
        block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]] == 1) {
        block_mx[block_index[valet[i]]]--;
    }
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]--;
    cnt[valet[i]]--;
    block_cnt_of_cnt[block_index[valet[i]]][cnt[valet[i]]]++;
}

int get_mode() {
    int mx = 0;
    for (int i = 0; i < A / SQRTA + 1; i++) {
        mx = std::max(mx, block_mx[i]);
    }
    for (int i = 0;; i++) {
        if (block_mx[i] == mx) {
            for (int j = i * SQRTA;; j++) {
                if (cnt[j] == mx) {
                    return j;
                }
            }
        }
    }
}

Query queries[N];
int ans[N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        std::cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, -1, 0);

    std::vector<std::pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) {
        ord[i] = {sz[i], i};
        gr[i] = -1;
    }

    std::sort(ord.begin(), ord.end());

    for (int i = 0; i < n; i++) {
        if (sz[i] >= B) {
            heavy[i] = true;
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int v = ord[i].second;
        if (sz[v] < B || gr[v] != -1) {
            continue;
        }

        leaf[cur] = v;

        int u = v;
        while (gr[u] == -1 && sz[u] - sz[v] < B) {
            gr[u] = cur;
            group_root[cur] = u;
            u = par[u];
        }

        cur++;
    }

    dfs2(0);

    for (int i = 0; i < n; i++) {
        if (sz[i] < B) {
            gr[i] = cur + tin[i] / B;
        }
    }

    for (int i = 0; i < n; i++)
        valet[i] = val[et[i]];

    for (int i = 0; i < A; i++) {
        block_index[i] = i / SQRTA;
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        queries[i].ind = i;
        std::cin >> queries[i].v >> queries[i].u;

        queries[i].v--;
        queries[i].u--;

        queries[i].lv = tin[queries[i].v];
        queries[i].rv = tout[queries[i].v];
        queries[i].lu = tin[queries[i].u];
        queries[i].ru = tout[queries[i].u];

        if (queries[i].lv > queries[i].lu) {
            std::swap(queries[i].v, queries[i].u);
            std::swap(queries[i].lv, queries[i].lu);
            std::swap(queries[i].rv, queries[i].ru);
        }

        queries[i].b = gr[queries[i].v];
    }

    std::sort(queries, queries + q, cmp);

    int lv = 0, rv = 0, lu = 0, ru = 0;
    ll fir = 0, sec = 0;

    int hs = 0;
    for (int i = 0; i < q; i++) {
        int qlv = queries[i].lv;
        int qrv = queries[i].rv;
        int qlu = queries[i].lu;
        int qru = queries[i].ru;

        fir += abs(lv - qlv) + abs(rv - qrv);
        sec += abs(lu - qlu) + abs(ru - qru);

        if (queries[i].b < cur) {
            while (rv < qrv) {
                insert(rv++);
            }
            while (lv > qlv) {
                insert(--lv);
            }
            while (rv > qrv) {
                erase(--rv);
            }
            while (lv < qlv) {
                erase(lv++);
            }
        } else {
            while (rv > lv)
                erase(--rv);
            lv = qlv;
            rv = lv;
            while (rv < qrv)
                insert(rv++);
        }

        while (ru < qru) {
            insert(ru++);
        }
        while (lu > qlu) {
            insert(--lu);
        }
        while (ru > qru) {
            erase(--ru);
        }
        while (lu < qlu) {
            erase(lu++);
        }

        ans[queries[i].ind] = get_mode();
    }

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << '\n';
    }
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
