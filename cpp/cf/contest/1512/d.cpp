#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 2);
    for (int i = 0; i < n + 2; i++) {
        std::cin >> b[i];
    }

    std::multiset<int> vis(b.begin(), b.end());
    ll sum = std::accumulate(b.begin(), b.end(), 0LL);
    for (int x : b) {
        vis.erase(vis.find(x));
        sum -= x;
        if (sum % 2 == 0 && sum <= 2'000'000'000 &&
            vis.find(sum / 2) != vis.end()) {
            vis.erase(vis.find(sum / 2));
            for (int y : vis) {
                std::cout << y << " ";
            }
            std::cout << '\n';
            return;
        }
        sum += x;
        vis.insert(x);
    }
    std::cout << "-1\n";
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
