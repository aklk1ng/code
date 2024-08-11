#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<ll> a(n + 5), p(n + 1), ans(n + 5), ord(n);
    std::set<int> s{0, n + 1};
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        p[i] = p[i - 1] + a[i];
        ord.push_back(i);
    }

    std::sort(ord.begin(), ord.end(),
              [&](int t1, int t2) { return a[t1] > a[t2]; });
    for (auto i : ord) {
        int l = *(--s.lower_bound(i));
        int r = *s.lower_bound(i);
        ll sum = p[r - 1] - p[l];
        if (i == ord[0]) {
            ans[i] = true;
        }
        if (sum >= a[l]) {
            ans[i] |= ans[l];
        }
        if (sum >= a[r]) {
            ans[i] |= ans[r];
        }
        s.insert(i);
    }
    std::cout << std::accumulate(ans.begin(), ans.end(), 0) << "\n";
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
