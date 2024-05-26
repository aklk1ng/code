#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    bool ok = false;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] == 1) {
            ok = true;
        }
    }
    if (ok) {
        std::cout << "YES\n";
        return;
    }
    std::sort(a.begin() + 1, a.end());
    std::vector<int> b;
    for (int i = 2; i <= n; i++) {
        if (a[i] % a[1]) {
            b.push_back(a[i]);
        }
    }
    std::sort(b.begin(), b.end());
    int sz = b.size();
    for (int j = 1; j < sz; j++) {
        if (b[j] % b[0]) {
            ok = true;
            break;
        }
    }
    std::cout << (ok ? "NO" : "YES") << '\n';
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
