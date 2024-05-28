#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::mt19937_64
    rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> tbl(n, std::vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            std::cin >> c;
            tbl[i][j] = c - '0';
        }
    }

    std::vector<ll> t1(n), t2(n);
    for (int i = 0; i < n; i++) {
        t1[i] = rnd();
        t2[i] = rnd();
    }
    std::map<std::pair<ll, ll>, int> ans;
    int res = 0;
    std::pair<int, int> ind = {0, 0};
    for (int j = 0; j < m; j++) {
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (tbl[i][j]) {
                sum1 ^= t1[i];
                sum2 ^= t2[i];
            }
        }
        for (int i = 0; i < n; i++) {
            sum1 ^= t1[i];
            sum2 ^= t2[i];
            ans[{sum1, sum2}]++;
            if (res < ans[{sum1, sum2}]) {
                res = ans[{sum1, sum2}];
                ind = {j, i};
            }
            sum1 ^= t1[i];
            sum2 ^= t2[i];
        }
    }
    std::cout << res << '\n';
    std::string inds(n, '0');
    for (int i = 0; i < n; i++) {
        if (tbl[i][ind.first]) {
            if (i != ind.second) {
                inds[i] = '1';
            }
        } else if (ind.second == i) {
            inds[i] = '1';
        }
    }
    std::cout << inds << '\n';
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
