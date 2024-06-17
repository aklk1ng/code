#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << "0\n";
        return;
    }
    int mx = *std::max_element(a.begin() + 1, a.end());
    int mxc = std::max(a[0] + c, mx);
    int win =
        mxc == a[0] + c ? 0 : std::find(a.begin() + 1, a.end(), mx) - a.begin();
    ll sum = c;
    for (int i = 0; i < n; sum += a[i], i++) {
        int ans;
        if (i == win) {
            ans = 0;
        } else if (sum + a[i] >= mx) {
            ans = i;
        } else {
            ans = i + 1;
        }
        std::cout << ans << " \n"[i == n - 1];
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
