#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    ll k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    std::vector<int> f(n, n);

    for (int d = 29; d >= 0; d--) {
        std::map<int, int> p;
        auto nf = f;
        for (int i = 0; i < n; i++) {
            if (p.count((a[i] ^ ans) >> d)) {
                int j = p[(a[i] ^ ans) >> d];
                nf[j] = std::min(nf[j], i);
            }
            p[a[i] >> d] = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            nf[i] = std::min(nf[i], nf[i + 1]);
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += n - nf[i];
        }
        if (sum < k) {
            ans |= 1 << d;
            f = nf;
        }
    }
    std::cout << ans << '\n';
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
