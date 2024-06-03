#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 111;

struct edge {
    int y, c, w, f;
    edge(){};
    edge(int y, int c, int w, int f) : y(y), c(c), w(w), f(f){};
};

std::vector<edge> e;
std::vector<int> g[N];

int rem(int x) { return e[x].c - e[x].f; }

void add_edge(int x, int y, int c, int w) {
    g[x].push_back(e.size());
    e.push_back(edge(y, c, w, 0));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, -w, 0));
}

int n, m, s, t, v;

std::pair<int, ll> MCMF() {
    int flow = 0;
    ll cost = 0;
    while (true) {
        std::vector<ll> d(v, (ll)(1e18));
        std::vector<int> p(v, -1), pe(v, -1);
        std::queue<int> q;
        std::vector<bool> inq(v);
        q.push(s);
        inq[s] = true;
        d[s] = 0;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            inq[k] = false;
            for (auto ei : g[k]) {
                if (rem(ei) == 0) {
                    continue;
                }
                int to = e[ei].y;
                int w = e[ei].w;
                if (d[to] > d[k] + w) {
                    d[to] = d[k] + w;
                    p[to] = k;
                    pe[to] = ei;
                    if (!inq[to]) {
                        inq[to] = true;
                        q.push(to);
                    }
                }
            }
        }
        if (p[t] == -1) {
            break;
        }
        flow++;
        cost += d[t];
        int cur = t;
        while (cur != s) {
            e[pe[cur]].f++;
            e[pe[cur] ^ 1].f--;
            cur = p[cur];
        }
    }
    return std::make_pair(flow, cost);
}

int get_sum(const std::vector<int> &v) {
    int sum = 0;
    for (auto x : v) {
        sum += x;
    }
    return sum;
}

void solve() {
    std::cin >> n >> m;
    s = n + m;
    t = n + m + 1;
    v = n + m + 2;
    int sum_matrix = 0;
    std::vector<int> A(n), B(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            sum_matrix += x;
            if (x == 1) {
                add_edge(i, j + n, 1, 0);
            } else {
                add_edge(i, j + n, 1, 1);
            }
        }
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
        add_edge(s, i, A[i], 0);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
        add_edge(i + n, t, B[i], 0);
    }

    auto ans = MCMF();
    if (ans.first != get_sum(A) || ans.first != get_sum(B)) {
        std::cout << -1 << '\n';
    } else {
        std::cout << sum_matrix - ans.first + ans.second * 2 << '\n';
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
