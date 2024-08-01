using ll = long long;
#include <bits/stdc++.h>
const int mod = 998244353;

struct query {
    int i, j;
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<query>> g(n + 1);
    for (int j = 0; j < q; j++) {
        int i, x;
        std::cin >> i >> x;
        i--;
        g[x].push_back({i, j});
    }

    for (int i = 0; i <= n; i++) {
        std::sort(g[i].begin(), g[i].end(),
                  [](const query &x, const query &y) { return x.i > y.i; });
    }
    int P = std::min(1000, n + 1);
    std::vector<char> ans(q);
    for (int k = 1; k < P; k++) {
        int cur = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            if (a[i] >= cur) {
                cnt++;
                ok = true;
                if (cnt == k) {
                    cur++;
                    cnt = 0;
                }
            }
            while (!g[k].empty() && g[k].back().i == i) {
                ans[g[k].back().j] = ok;
                g[k].pop_back();
            }
        }
    }
    std::vector<int> sum1(n), sum2(n);
    int p2 = ceil(sqrt(n + 2));
    auto add = [&](int i) {
        int bl = i / p2;
        for (int j = bl + 1; j * p2 < n; ++j) {
            ++sum1[j];
        }
        for (int j = i; j < (bl + 1) * p2 && j < n; ++j) {
            ++sum2[j];
        }
    };
    int mx = n / P + 5;
    std::vector<std::vector<int>> pos(mx);
    for (int i = 0; i < n; i++) {
        if (a[i] < mx) {
            pos[a[i]].push_back(i);
        } else {
            add(i);
        }
    }
    for (auto &e : pos) {
        std::reverse(e.begin(), e.end());
    }
    for (int k = P; k <= n; k++) {
        while (true) {
            int mi = n, who = -1;
            for (int l = 0; l < mx; l++) {
                if (!pos[l].empty()) {
                    int i = pos[l].back();
                    if (mi < i) {
                        continue;
                    }
                    int cnt = sum1[i / p2] + sum2[i];
                    if (a[i] >= cnt / k + 1) {
                        mi = i;
                        who = l;
                    }
                }
            }
            if (who == -1) {
                break;
            }
            add(mi);
            pos[who].pop_back();
        }
        for (auto &e : g[k]) {
            int l = a[e.i];
            ans[e.j] = (l >= mx || pos[l].empty() || pos[l].back() > e.i);
        }
    }
    for (auto &e : ans) {
        std::cout << (e ? "Yes" : "No") << '\n';
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
