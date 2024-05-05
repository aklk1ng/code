#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int m;
    std::cin >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    auto cal = [&](auto self, int l, int r) -> int {
        if (r - l == 1) {
            return 0;
        }
        int mid = (l + r) >> 1;
        int mxl = *std::max_element(a.begin() + l, a.begin() + mid);
        int mxr = *std::max_element(a.begin() + mid, a.begin() + r);
        int res = 0;
        if (mxl > mxr) {
            res++;
            for (int i = 0; i < (mid - l); i++) {
                std::swap(a[l + i], a[mid + i]);
            }
        }
        return self(self, l, mid) + self(self, mid, r) + res;
    };
    int ans = cal(cal, 0, m);
    std::cout << (std::is_sorted(a.begin(), a.begin() + m) ? ans : -1) << '\n';
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
