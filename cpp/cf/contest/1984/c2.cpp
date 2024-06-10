#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const ll N = 400001;

std::vector<ll> p2(N);

void init() {
    p2[0] = 1;
    for (int i = 1; i < N; ++i) {
        p2[i] = 2 * p2[i - 1] % mod;
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    ll sum = 0, mi = 0, ans = 0, abses = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i], mi = std::min(mi, sum);
    }
    if (mi == 0) {
        std::cout << p2[n] << '\n';
        return;
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum == mi) {
            ans = (ans + p2[n - i - 1 + abses]) % mod;
        }
        if (sum >= 0) {
            ++abses;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    init();
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
