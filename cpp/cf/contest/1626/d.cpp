#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
std::vector<int> nxt = {1, 0};
int calc = 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    while (calc <= n) {
        for (int i = 0; i < calc; i++) {
            nxt.push_back(calc - i - 1);
        }
        calc *= 2;
    }
    std::vector<int> left(n + 1);
    for (int i = 0; i < n; i++) {
        if (!i || i == n || a[i] != a[i - 1]) {
            left[i] = i;
        } else {
            left[i] = left[i - 1];
        }
    }
    int m = 1, ans = n + 2;
    while (m <= n) {
        for (int len1 = 0; len1 <= n; ++len1) {
            if (left[len1] == len1) {
                int len2 = left[std::min(n, len1 + m)] - len1;
                int len3 = n - len1 - len2;
                ans = std::min(ans, nxt[len1] + (m - len2) + nxt[len3]);
            }
        }
        m *= 2;
    }

    std::cout << ans << '\n';
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
