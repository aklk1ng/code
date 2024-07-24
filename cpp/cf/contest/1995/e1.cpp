#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
#define M(x) (((x) + 2 * n) % (2 * n))
    int n;
    std::cin >> n;
    std::vector<int> v(2 * n);
    for (auto &e : v) {
        std::cin >> e;
    }

    if (n % 2 == 0) {
        int ma = 0;
        int mi = 2'000'000'001;
        for (int i = 0; i < n / 2; ++i) {
            int s[4]{v[2 * i] + v[2 * i + 1], v[2 * i] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + 1]};
            std::sort(s, s + 4);
            ma = std::max(ma, s[2]);
            mi = std::min(mi, s[1]);
        }
        std::cout << ma - mi << '\n';
        return;
    }
    if (n == 1) {
        std::cout << 0 << '\n';
        return;
    }
    std::vector<int> r;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        r.push_back(v[cur]);
        r.push_back(v[cur ^= 1]);
        cur = M(cur + n);
    }

    int ans = 2'000'000'001;
    for (int id = 0; id < n; ++id) {
        for (int m1 = 0; m1 < 2; ++m1) {
            for (int m2 = 0; m2 < 2; ++m2) {
                int mi_value = r[M(2 * id - m1)] + r[M(2 * id + 1 + m2)];
                std::vector<int> dp[2]{std::vector<int>(n, 2'000'000'001),
                                       std::vector<int>(n, 2'000'000'001)};
                dp[m2][id] = mi_value;
                for (int j = 1; j < n; ++j) {
                    int jd = (id + j) % n;
                    int pd = (id + j - 1) % n;
                    for (int pc = 0; pc < 2; ++pc) {
                        for (int jc = 0; jc < 2; ++jc) {
                            if (dp[pc][pd] != 2'000'000'001 &&
                                r[M(2 * jd - pc)] + r[M(2 * jd + 1 + jc)] >=
                                    mi_value) {
                                dp[jc][jd] = std::min(
                                    dp[jc][jd],
                                    std::max(dp[pc][pd],
                                             r[M(2 * jd - pc)] +
                                                 r[M(2 * jd + 1 + jc)]));
                            }
                        }
                    }
                }
                int pd = (id + n - 1) % n;
                if (dp[m1][pd] != 2'000'000'001) {
                    ans = std::min(ans, dp[m1][pd] - mi_value);
                }
            }
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
