#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a, b, v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    for (auto &e : v) {
        int x;
        std::cin >> x;
        if (x == 1) {
            a.push_back(e);
        } else {
            b.push_back(e);
        }
    }

    std::sort(a.rbegin(), a.rend());
    std::sort(b.rbegin(), b.rend());
    ll suma = 0;
    int r = b.size();
    ll sumb = std::accumulate(b.begin(), b.end(), 0LL);
    int ans = INT_MAX;
    for (int l = 0; l <= a.size(); l++) {
        while (r > 0 && suma + sumb - b[r - 1] >= m) {
            r--;
            sumb -= b[r];
        }
        if (sumb + suma >= m) {
            ans = std::min(ans, 2 * r + l);
        }
        if (l != a.size()) {
            suma += a[l];
        }
    }
    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
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
