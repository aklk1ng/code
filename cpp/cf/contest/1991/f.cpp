#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> p(n + 1);
    auto can = [&](int l, int r) -> bool {
        int t = 0;
        for (int i = l; i <= r; i++) {
            p[++t] = a[i];
        }
        std::sort(p.begin() + 1, p.begin() + 1 + t);
        for (int i = 1; i <= t - 5; i++) {
            for (int j = i + 1; j <= i + 5; j++) {
                for (int k = j + 1; k <= i + 5; k++) {
                    int q[4], c = 0;
                    for (int m = i + 1; m <= i + 5; m++) {
                        if (m != j && m != k) {
                            q[++c] = p[m];
                        }
                    }
                    if (p[i] + p[j] > p[k] && q[1] + q[2] > q[3]) {
                        return true;
                    }
                }
            }
        }
        int triangleCount = 0;
        for (int i = 1; i <= t - 2; i++) {
            if (p[i] + p[i + 1] > p[i + 2]) {
                i += 2;
                triangleCount++;
            }
        }
        return triangleCount > 1;
    };
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        if (r - l + 1 >= 48 || can(l, r)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
