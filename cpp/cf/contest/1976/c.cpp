#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    const int N = n + m + 1;
    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    int t = 0, x = 0, y = 0;
    ll sum = 0;
    while (x < n && y < m) {
        if (a[t] > b[t]) {
            sum += a[t];
            x++;
        } else {
            sum += b[t];
            y++;
        }
        t++;
    }
    std::vector<ll> ans(N);
    ll res = sum;
    for (int i = t; i < N; i++) {
        res += x == n ? b[i] : a[i];
    }
    for (int i = t; i < N; i++) {
        ans[i] = res - (x == n ? b[i] : a[i]);
    }
    for (int i = 0; i < t; i++) {
        if ((x == n) == (a[i] < b[i])) {
            ans[i] = res - std::max(a[i], b[i]);
        }
    }
    int ot = t;
    int ox = x;
    if (x == n) {
        x--;
    } else {
        y--;
    }
    while (x < n && y < m) {
        if (a[t] > b[t]) {
            sum += a[t];
            x++;
        } else {
            sum += b[t];
            y++;
        }
        t++;
    }
    res = sum;
    for (int i = t; i < N; i++) {
        res += x == n ? b[i] : a[i];
    }
    for (int i = 0; i < ot; i++) {
        if ((ox == n) == (a[i] > b[i])) {
            ans[i] = res - std::max(a[i], b[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
