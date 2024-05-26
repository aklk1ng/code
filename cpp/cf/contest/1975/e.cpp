#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 10;

int f[N];
std::vector<int> g[N];
int col[N], num[N];
int faw, sum_two, sum_more, tot_black, xor_two;
int n;

void init() {
    sum_two = 0;
    tot_black = 0;
    sum_more = 0;
    faw = 0;
    xor_two = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        num[i] = 0;
    }
}

void dfs(int x, int fa) {
    f[x] = fa;
    if (col[x] == 1) {
        tot_black++;
    }
    int sum = 0;
    for (auto i : g[x]) {
        if (i == fa) {
            continue;
        }
        dfs(i, x);
        if (col[i] == 1) {
            sum++;
        }
    }
    if (col[fa] == 0 && col[x] == 1) {
        faw++;
    }
    if (col[x] == 1) {
        if (sum == 2) {
            sum_two++, xor_two ^= x;
        }
        if (sum > 2) {
            sum_more++;
        }
    }
    num[x] = sum;
}

void flip(int x) {
    col[x] ^= 1;
    int d = col[x] == 1 ? 1 : -1;
    tot_black += d;
    if (col[f[x]] == 0) {
        faw += d;
    }
    if (num[x] == 2) {
        sum_two += d, xor_two ^= x;
    }
    if (num[x] > 2) {
        sum_more += d;
    }
    faw -= d * num[x];
    if (col[x] == 1) {
        if (col[f[x]] == 1 && num[f[x]] == 2) {
            sum_two--, sum_more++, xor_two ^= f[x];
        }
        num[f[x]]++;
        if (col[f[x]] == 1 && num[f[x]] == 2) {
            sum_two++, xor_two ^= f[x];
        }
    } else {
        if (col[f[x]] == 1 && num[f[x]] == 2) {
            sum_two--, xor_two ^= f[x];
        }
        num[f[x]]--;
        if (col[f[x]] == 1 && num[f[x]] == 2) {
            sum_two++;
            sum_more--;
            xor_two ^= f[x];
        }
    }
}

bool check() {
    if (!tot_black) {
        return false;
    }
    if (sum_more || sum_two > 1) {
        return false;
    }
    if (faw > 1) {
        return false;
    }
    if (sum_two && col[f[xor_two]] == 1) {
        return false;
    }
    return true;
}

void solve() {
    init();
    int q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> col[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    while (q--) {
        int x;
        std::cin >> x;
        flip(x);
        if (check()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
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
