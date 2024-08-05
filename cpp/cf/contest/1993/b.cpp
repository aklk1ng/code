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

    ll s = -1;
    std::vector<int> v;
    for (auto &e : a) {
        if (e % 2 == 0) {
            v.push_back(e);
        } else if (e > s) {
            s = e;
        }
    }
    std::sort(v.begin(), v.end());
    if (s == -1 || v.empty()) {
        std::cout << "0\n";
        return;
    }

    int ans = v.size();
    for (auto &e : v) {
        if (e < s) {
            s += e;
        } else {
            ans++;
            break;
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
