#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int K = 1e9 + 1;
int n;

std::vector<int> cal(std::vector<std::vector<int>> a) {
    std::vector<std::pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = {a[i][0], i};
        r[i] = {a[i][1], i};
    }
    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());
    std::vector<std::vector<std::pair<int, int>>> suf(n);
    std::vector<std::pair<int, int>> curr;
    for (int i0 = n - 1; i0 >= 0; --i0) {
        int xr = r[i0].first;
        int i = r[i0].second;
        int xl = a[i][0];
        int c = a[i][2];
        if (curr.empty()) {
            curr.emplace_back(xl, c);
        } else if (curr.size() == 1) {
            if (curr[0].second == c) {
                curr[0].first = std::min(curr[0].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        } else {
            if (curr[0].second == c) {
                curr[0].first = std::min(curr[0].first, xl);
            } else if (curr[1].second == c) {
                curr[1].first = std::min(curr[1].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        }
        std::sort(curr.begin(), curr.end());
        if (curr.size() == 3) {
            curr.pop_back();
        }
        suf[i0] = curr;
    }
    std::vector<int> ans(n, 1e9);
    int j = 0;
    for (int i0 = 0; i0 < n; ++i0) {
        int xl = l[i0].first, i = l[i0].second;
        int xr = a[i][1], c = a[i][2];
        while (j < n && r[j].first < xl) {
            j++;
        }
        if (j < n) {
            std::vector<std::pair<int, int>> s = suf[j];
            if (s[0].second != c) {
                ans[i] = std::min(ans[i], std::max(0, s[0].first - xr));
            } else if (s.size() == 2) {
                ans[i] = std::min(ans[i], std::max(0, s[1].first - xr));
            }
        }
    }
    return ans;
}

void solve() {
    std::cin >> n;
    std::vector a(n, std::vector<int>(3)), b(n, std::vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
            if (j == 2) {
                b[i][j] = a[i][j];
            } else {
                b[i][1 - j] = K - a[i][j];
            }
        }
    }

    std::vector<int> ans1(cal(a)), ans2(cal(b));
    for (int i = 0; i < n; i++) {
        std::cout << std::min(ans1[i], ans2[i]) << " \n"[i == n - 1];
    }
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
