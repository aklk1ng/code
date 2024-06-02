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

    auto cal = [&]() {
        int ind = std::max_element(a.begin(), a.end()) - a.begin();
        std::vector<int> dp1(n, INT_MAX);
        dp1[0] = -1;
        for (int i = 1; i <= ind; i++) {
            if (a[i] > dp1[i - 1]) {
                dp1[i] = std::min(dp1[i], a[i - 1]);
            }
            if (a[i] > a[i - 1]) {
                dp1[i] = std::min(dp1[i], dp1[i - 1]);
            }
        }
        std::vector<int> dp2(n, INT_MAX);
        dp2[n - 1] = -1;
        for (int i = n - 2; i >= ind; i--) {
            if (a[i] > dp2[i + 1]) {
                dp2[i] = std::min(dp2[i], a[i + 1]);
            }
            if (a[i] > a[i + 1]) {
                dp2[i] = std::min(dp2[i], dp2[i + 1]);
            }
        }

        std::vector<std::array<int, 2>> dp3(n, {INT_MAX, INT_MIN});
        dp3[ind][0] = dp1[ind];
        int ans = 0;
        for (int i = ind + 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                dp3[i][0] = std::min(dp3[i][0], dp3[i - 1][0]);
            }
            if (dp3[i - 1][1] > a[i]) {
                dp3[i][0] = std::min(dp3[i][0], a[i - 1]);
            }

            if (a[i - 1] < a[i]) {
                dp3[i][1] = std::max(dp3[i][1], dp3[i - 1][1]);
            }
            if (dp3[i - 1][0] < a[i]) {
                dp3[i][1] = std::max(dp3[i][1], a[i - 1]);
            }

            if (dp3[i][1] > dp2[i]) {
                ans++;
            }
        }
        return ans;
    };
    int ans = cal();
    std::reverse(a.begin(), a.end());
    std::cout << ans + cal() << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
