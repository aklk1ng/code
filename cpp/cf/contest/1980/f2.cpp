#include <bits/stdc++.h>
using ll = long long;
#define int long long
const int mod = 998244353;

bool cmp(std::pair<int, int> &a, std::pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> a(k);
    std::map<std::pair<int, int>, int> idx;
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i].first >> a[i].second;
        idx[a[i]] = i;
    }

    idx[{0, 0}] = k++;
    a.emplace_back(0, 0);
    std::sort(a.begin(), a.end(), cmp);
    std::vector<int> ans(k);
    std::vector<int> total(k + 1), cur(k + 1, m + 1), last(k + 1, n);
    for (int i = 1; i <= k; ++i) {
        auto e = a[i - 1];
        total[i] = total[i - 1];
        cur[i] = cur[i - 1];
        last[i] = last[i - 1];
        if (cur[i] > e.second) {
            ans[idx[e]] = 1;
            total[i] += 1LL * (cur[i] - 1) * (last[i] - e.first);
            cur[i] = e.second;
            last[i] = e.first;
        }
    }
    std::cout << total[k] << "\n";
    for (int i = 1; i <= k; ++i) {
        auto e = a[i - 1];
        if (ans[idx[e]] == 0) {
            continue;
        }
        int tot = total[i - 1];
        int cr = cur[i - 1];
        int lst = last[i - 1];
        for (int j = i + 1; j <= k; ++j) {
            auto ee = a[j - 1];
            if (cr > ee.second) {
                tot += 1LL * (cr - 1) * (lst - ee.first);
                cr = ee.second;
                lst = ee.first;
            }
            if (ans[idx[ee]] == 1) {
                ans[idx[e]] = tot - total[j];
                break;
            }
        }
    }
    ans.pop_back();
    for (int e : ans) {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

signed main() {
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
