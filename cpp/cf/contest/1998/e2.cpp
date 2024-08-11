#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<ll> a(n + 1);
    std::vector<ll> p(n + 1);
    std::vector rmq(n + 5, std::vector<ll>(18));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        p[i] = p[i - 1] + a[i];
        rmq[i][0] = a[i] + p[i];
    }

    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = std::max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    std::vector<std::vector<int>> add(n + 5), rem(n + 5);
    auto ins = [&](int l, int r, int v) {
        l = std::max(l, 1);
        if (l > r) {
            return;
        }

        add[l].push_back(v);
        rem[r + 1].push_back(v);
    };
    for (int r = 1; r <= n; r++) {
        if (a[r] > p[r - 1]) {
            ins(1, r - 1, r);
        }

        int lowerB = std::upper_bound(p.begin() + 1, p.begin() + n + 1,
                                      p[r - 1] - a[r]) -
                     p.begin();
        int lo = lowerB, hi = r - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            int lg = 31 - __builtin_clz(mid - lowerB + 1);
            ll val = std::max(rmq[lowerB][lg], rmq[mid - (1 << lg) + 1][lg]);
            val > p[r - 1] ? hi = mid : lo = mid + 1;
        }
        ins(lo + 1, r - 1, r);
    }
    std::multiset<int> badR{n + 1};
    std::vector<int> ans(n + 5, 0);
    ll worst = 0;
    for (int i = 1; i <= n; i++) {
        for (int v : add[i]) {
            badR.insert(v);
        }
        for (int v : rem[i]) {
            badR.erase(badR.find(v));
        }

        int l = std::lower_bound(p.begin() + i, p.begin() + n + 1, worst) -
                p.begin();
        int r = *badR.begin();

        if (l <= r) {
            ans[l]++;
            ans[r]--;
        }
        worst = std::max(worst, a[i] + p[i]);
    }

    for (int i = x; i <= n; i++) {
        ans[i] += ans[i - 1];
        std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
