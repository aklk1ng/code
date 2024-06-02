#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int K = 30;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(n);
    std::vector up(n, std::vector<int>(K));
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        a--;
        cnt[a]++;
        up[i][0] = a;
    }
    for (int k = 1; k < K; k++) {
        for (int i = 0; i < n; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    std::vector<int> a(n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (!cnt[i]) {
            t++;
        }
    }
    int k = (*std::max_element(a.begin(), a.end()) - n) / t;
    std::vector<std::vector<int>> add(n);
    for (int i = 0; i < n; i++) {
        int v = i, level = k;
        for (int j = K - 1; j >= 0; j--) {
            if (level >= (1 << j)) {
                level -= 1 << j;
                v = up[v][j];
            }
        }
        add[a[v] - 1].push_back(i);
    }
    std::set<int> now;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (!add[i].empty()) {
            int res = *std::min_element(add[i].begin(), add[i].end());
            for (int &j : add[i]) {
                if (j != res) {
                    now.emplace(j);
                }
            }
            ans[res] = i + 1;
        } else {
            ans[*now.begin()] = i + 1;
            now.erase(*now.begin());
        }
    }
    for (int &e : ans) {
        std::cout << e << " \n"[e == ans.back()];
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
