#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::set<int> divs(int n) {
    std::set<int> d;
    for (int dd = 1; dd * dd <= n; dd++)
        if (n % dd == 0) {
            d.insert(n / dd);
            d.insert(dd);
        }
    return d;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int k = -1;

    for (int i = 0; i < n; i++) {
        int minv = a[i];
        int same = 0;
        std::vector<int> d;
        for (int j = 0; j < n; j++) {
            if (a[j] == minv) {
                same++;
            } else if (a[j] > minv) {
                d.push_back(a[j] - minv);
            }
        }
        if (same >= n / 2) {
            k = INT_MAX;
            continue;
        }
        std::map<int, int> div_counts;
        for (int di : d) {
            for (int dd : divs(di)) {
                div_counts[dd]++;
            }
        }
        for (auto p : div_counts)
            if (p.second >= n / 2 - same) {
                k = std::max(k, p.first);
            }
    }

    std::cout << (k == INT_MAX ? -1 : k) << '\n';
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
