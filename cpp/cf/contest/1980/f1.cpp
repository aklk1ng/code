#include <bits/stdc++.h>
using ll = long long;
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

    std::sort(a.begin(), a.end(), cmp);
    std::vector<int> ans(k);
    ll total = 0;
    int cur = m + 1;
    int last = n;
    for (auto e : a) {
        if (cur > e.second) {
            ans[idx[e]] = 1;
            total += 1LL * (cur - 1) * (last - e.first);
            cur = e.second;
            last = e.first;
        }
    }
    total += 1LL * (cur - 1) * last;
    std::cout << total << "\n";
    for (int e : ans) {
        std::cout << e << " ";
    }
    std::cout << '\n';
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
