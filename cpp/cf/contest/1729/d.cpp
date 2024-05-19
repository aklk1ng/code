#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> x(n), y(n);
    std::vector<std::pair<ll, int>> diff(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }

    for (int i = 0; i < n; i++) {
        diff[i].first = y[i] - x[i];
        diff[i].second = i;
    }
    std::sort(diff.begin(), diff.end());
    std::reverse(diff.begin(), diff.end());
    int j = n - 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        while (j > i && diff[i].first + diff[j].first < 0) {
            j--;
        }
        if (j <= i) {
            break;
        }
        cnt++;
        j--;
    }
    std::cout << cnt << '\n';
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
