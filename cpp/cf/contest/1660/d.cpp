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

    int ans = 0;
    int ap = n, as = 0;
    for (int i = 0, l = -1; i <= n; i++) {
        if (i == n || a[i] == 0) {
            int cnt = 0;
            bool ok = false;
            int left = -1, right = -1;
            int cl = 0, cr = 0;
            for (int j = l + 1; j < i; j++) {
                ok ^= a[j] < 0;
                if (a[j] < 0) {
                    right = j;
                    cr = 0;
                }
                if (std::abs(a[j]) == 2) {
                    cnt++;
                    cr++;
                    if (left == -1) {
                        cl++;
                    }
                }
                if (a[j] < 0 && left == -1) {
                    left = j;
                }
            }
            if (ok) {
                if (cnt - cl > cnt - cr) {
                    right = i;
                    cnt -= cl;
                } else {
                    left = l;
                    cnt -= cr;
                }
            } else {
                left = l;
                right = i;
            }
            if (ans < cnt) {
                ans = cnt;
                ap = left + 1;
                as = n - right;
            }
            l = i;
        }
    }
    std::cout << ap << ' ' << as << '\n';
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
