#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        a[i] = {v[i], i};
    }

    std::sort(a.begin(), a.end());
    std::vector<int> p(n);
    int j = 0;
    std::unordered_multiset<int> nxt;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].first != a[i - 1].first) {
            j++;
        }
        p[a[i].second] = j;
        nxt.insert(j);
    }
    std::unordered_map<int, int> d;
    std::vector<int> dp1(n), dp2(n), dp3(n), cnt(n);
    for (int i = 0; i < n; i++) {
        if (nxt.count(p[i])) {
            nxt.erase(nxt.find(p[i]));
        }
        if (d.count(p[i] - 1)) {
            if (!d.count(p[i])) {
                dp2[i] = std::max(dp2[i], dp1[d[p[i] - 1]] + 1);
                if (!nxt.count(p[i] - 1)) {
                    dp2[i] = std::max(dp2[i], dp2[d[p[i] - 1]] + 1);
                }
            }
            if (!nxt.count(p[i] - 1)) {
                dp3[i] = std::max(dp3[i], dp2[d[p[i] - 1]] + 1);
            }
            dp3[i] = std::max(dp3[i], dp1[d[p[i] - 1]] + 1);
        }
        if (d.count(p[i])) {
            dp3[i] = std::max(dp3[i], dp3[d[p[i]]] + 1);
            dp2[i] = std::max(dp2[i], dp2[d[p[i]]] + 1);
            dp1[i] = dp1[d[p[i]]] + 1;
        } else {
            dp1[i] = 1;
        }
        dp2[i] = std::max(dp2[i], dp1[i]);
        dp3[i] = std::max(dp3[i], dp2[i]);
        d[p[i]] = i;
    }
    std::cout << n - *std::max_element(dp3.begin(), dp3.end()) << "\n";
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
