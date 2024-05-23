#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int m, x;
    std::cin >> m >> x;
    ll sum = 0;
    std::priority_queue<int> h;
    for (int i = 0; i < m; i++) {
        int c;
        std::cin >> c;

        h.push(c);
        sum -= c;

        if (sum < 0) {
            sum += h.top();
            h.pop();
        }
        sum += x;
    }
    std::cout << h.size() << '\n';
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
