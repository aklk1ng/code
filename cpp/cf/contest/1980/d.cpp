#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = std::gcd(a[i], a[i + 1]);
    }
    int bad = 0;
    for (int i = 1; i < n - 1; i++) {
        bad += b[i] < b[i - 1];
    }
    int ans = 0;
    if (bad - (b[1] < b[0]) == 0) {
        ans = 1;
    }
    if (bad - (b[n - 2] < b[n - 3]) == 0) {
        ans = 1;
    }
    for (int i = 1; i < n - 1; i++) {
        int t = bad;
        t -= b[i] < b[i - 1];
        int g = std::gcd(a[i - 1], a[i + 1]);
        if (i > 1) {
            t -= b[i - 1] < b[i - 2];
            t += g < b[i - 2];
        }
        if (i + 1 < n - 1) {
            t -= b[i + 1] < b[i];
            t += b[i + 1] < g;
        }
        if (!t) {
            ans = 1;
        }
    }
    std::cout << (ans ? "YES" : "NO") << '\n';
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
