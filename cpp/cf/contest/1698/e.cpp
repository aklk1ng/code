#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, s;
    std::cin >> n >> s;
    std::vector<std::pair<int, int>> a(n + 1);
    std::vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].second;
        if (a[i].second != -1) {
            vis[a[i].second] = true;
        }
    }

    std::vector<int> miss;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            miss.push_back(i);
        }
    }
    std::sort(a.begin() + 1, a.end(),
              [](std::pair<int, int> &x, std::pair<int, int> &y) {
                  return x.second < y.second;
              });
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].second != -1) {
            mx = std::max(mx, a[i].first - a[i].second);
        }
    }
    if (mx > s) {
        std::cout << "0\n";
        return;
    }
    std::vector<int> cnts;
    for (int i = 1; i <= n; i++) {
        if (a[i].second == -1) {
            cnts.push_back(miss.end() - std::lower_bound(miss.begin(),
                                                         miss.end(),
                                                         a[i].first - s));
        }
    }
    std::sort(cnts.begin(), cnts.end());
    ll ans = 1;
    for (int i = 0; i < cnts.size(); i++) {
        ans = (ans * (cnts[i] - i)) % mod;
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
