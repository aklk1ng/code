#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int logi(int a, int b) {
    int t = 0;
    ll v = 1;
    while (v < b) {
        v *= a;
        t++;
    }
    return t;
}

int llog(int a, int b) {
    if (a < b) {
        int l = logi(a, b);
        return (l == 0 ? 0 : std::__lg(2 * l - 1));
    }
    int l = logi(b, a + 1) - 1;
    assert(l > 0);
    return -std::__lg(l);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int t = 0;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > 1 && a[i] == 1) {
            std::cout << "-1\n";
            return;
        }
        if (a[i] == 1) {
            assert(!t);
            continue;
        }
        if (a[i - 1] == 1) {
            t = 0;
            continue;
        }
        int l = llog(a[i], a[i - 1]);
        t = std::max(0, t + l);
        ans += t;
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
