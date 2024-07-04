#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, x, y;
    std::cin >> n >> x >> y;
    std::string a, b;
    std::cin >> a >> b;

    ll d = 0;
    for (int i = 0; i < n; i++) {
        a[i] ^= b[i];
        d += a[i];
    }
    if (d % 2) {
        std::cout << "-1\n";
        return;
    }
    if (d == 2) {
        int l, r;
        for (l = 0; !a[l];) {
            l++;
        }
        for (r = n - 1; !a[r];) {
            r--;
        }
        if (l + 1 == r) {
            std::cout << std::min(x, 2 * y) << '\n';
        } else {
            std::cout << std::min((r - l) * x, y) << '\n';
        }
        return;
    }
    if (!d || x >= y) {
        std::cout << d / 2 * y << '\n';
        return;
    }
    std::vector z0(n + 1, std::vector<ll>(n + 1, 1LL << 60)),
        z1(n + 1, std::vector<ll>(n + 1, 1LL << 60));
    if (!a[0]) {
        z0[0][0] = 0;
    }
    if (a[0]) {
        z1[0][1] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i]) {
            for (int j = i + 1; j >= 0; j--) {
                if (j <= i) {
                    z0[i][j] =
                        std::min(z0[i - 1][j + 1] + y, z1[i - 1][j + 1] + x);
                }
                if (j) {
                    z0[i][j] = std::min(
                        {z0[i][j], z0[i - 1][j - 1] + x, z1[i - 1][j - 1] + y});
                    z1[i][j] = std::min(z0[i - 1][j - 1], z1[i - 1][j - 1]);
                }
            }
        } else {
            for (int j = i + 1; j >= 0; j--) {
                z0[i][j] = std::min(z0[i - 1][j], z1[i - 1][j]);
                z1[i][j] = std::min(z0[i - 1][j] + y, z1[i - 1][j] + x);
                if (j > 1) {
                    z1[i][j] = std::min(
                        {z1[i][j], z0[i - 1][j - 2] + x, z1[i - 1][j - 2] + y});
                }
            }
        }
    }
    std::cout << z0[n - 1][0] << '\n';
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
