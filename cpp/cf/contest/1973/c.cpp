#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    std::vector<int> q(n);
    int pos = std::find(p.begin(), p.end(), n) - p.begin();
    if (!(pos & 1)) {
        std::vector<std::pair<int, int>> v;
        for (int i = 1; i < n; i += 2) {
            v.push_back({p[i], i});
        }
        v.push_back({p[0], 0});
        for (int i = 2; i < n; i += 2) {
            v.push_back({p[i], i});
        }
        std::sort(v.begin(), v.begin() + (n / 2),
                  std::greater<std::pair<int, int>>());
        std::sort(v.begin() + (n / 2) + 1, v.begin() + n,
                  std::greater<std::pair<int, int>>());
        for (int i = 0; i < n; i++) {
            q[v[i].second] = i + 1;
        }
    } else {
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < n; i += 2) {
            v.push_back({p[i], i});
        }
        v.push_back({p[n - 1], n - 1});
        for (int i = 1; i < n - 1; i += 2) {
            v.push_back({p[i], i});
        }
        std::sort(v.begin(), v.begin() + (n / 2),
                  std::greater<std::pair<int, int>>());
        std::sort(v.begin() + (n / 2) + 1, v.begin() + n,
                  std::greater<std::pair<int, int>>());
        for (int i = 0; i < n; i++) {
            q[v[i].second] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << q[i] << " \n"[i == n - 1];
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
