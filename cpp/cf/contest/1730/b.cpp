#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> x(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
        x[i] *= 2;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        t[i] *= 2;
    }

    int l = -1, r = 1e9 + 7;
    while (l + 1 < r) {
        int m = (l + r) / 2;

        int mxl = 0, mir = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (t[i] > m) {
                mxl = 1e9 + 7;
                mir = 0;
                break;
            } else {
                mxl = std::max(mxl, x[i] - (m - t[i]));
                mir = std::min(mir, x[i] + (m - t[i]));
            }
        }
        if (mxl <= mir) {
            r = m;
        } else {
            l = m;
        }
    }
    int mxl = 0, mir = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        mxl = std::max(mxl, x[i] - (r - t[i]));
        mir = std::min(mir, x[i] + (r - t[i]));
    }
    std::cout << mxl / 2;
    if (mxl % 2) {
        std::cout << ".5";
    }
    std::cout << '\n';
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
