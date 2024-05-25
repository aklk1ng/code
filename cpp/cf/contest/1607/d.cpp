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
    std::string c;
    std::cin >> c;

    std::vector<int> l, r;
    for (int i = 0; i < n; i++) {
        (c[i] == 'B' ? l : r).push_back(a[i]);
    }
    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end(), std::greater<int>());
    bool ok = true;
    for (int i = 0; i < l.size(); i++) {
        if (l[i] < i + 1) {
            ok = false;
        }
    }
    for (int i = 0; i < r.size(); i++) {
        if (r[i] > n - i) {
            ok = false;
        }
    }
    std::cout << (ok ? "YES" : "NO") << '\n';
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
