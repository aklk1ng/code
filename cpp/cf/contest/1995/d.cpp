#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, c, k;
    std::cin >> n >> c >> k;
    std::string s;
    std::cin >> s;

    std::vector<int> f(1 << c);
    std::vector<int> nxt(c, n);
    for (int i = n - 1; i >= 0; i--) {
        int x = s[i] - 'A';
        if (i == n - 1) {
            f[(1 << c) - (1 << x) - 1]++;
        } else {
            int mask = 0;
            for (int j = 0; j < c; j++) {
                if (nxt[j] == n || nxt[j] - i > k) {
                    mask |= 1 << j;
                }
            }
            if (mask >> x & 1) {
                f[mask]++;
                f[mask ^ (1 << x)]--;
            }
        }
        nxt[x] = i;
    }
    int mask = 0;
    for (int j = 0; j < c; j++) {
        if (nxt[j] == n || nxt[j] >= k) {
            mask |= 1 << j;
        }
    }
    f[mask]++;

    for (int i = 1; i < (1 << c); i *= 2) {
        for (int j = 0; j < (1 << c); j += 2 * i) {
            for (int k = 0; k < i; k++) {
                f[j + k] += f[i + j + k];
            }
        }
    }
    int ans = c;
    for (int s = 0; s < (1 << c); s++) {
        if (f[s] == 0) {
            ans = std::min(ans, __builtin_popcount(s));
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
