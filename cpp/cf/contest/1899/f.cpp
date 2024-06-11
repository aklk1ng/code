#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b1, b2;
    for (int i = 0; i < n; ++i) {
        b1.push_back(i);
    }
    b2.push_back(1);
    for (int i = 1; i < n; ++i) {
        std::cout << i << ' ' << i + 1 << '\n';
    }
    int q;
    std::cin >> q;
    while (q--) {
        int d;
        std::cin >> d;
        d++;
        if (b1.size() == d) {
            std::cout << "-1 -1 -1\n";
        } else if (b1.size() < d) {
            d = d - b1.size();
            std::vector<int> qq(b2.end() - d, b2.end());
            int u = b2[b2.size() - d];
            int v1 = b2[b2.size() - d - 1];
            int v2 = b1.back();
            std::cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
            for (int i = 0; i < d; ++i) {
                b2.pop_back();
            }
            for (auto i : qq) {
                b1.push_back(i);
            }
        } else {
            d = b1.size() - d;
            std::vector<int> qq(b1.end() - d, b1.end());
            int u = b1[b1.size() - d];
            int v1 = b1[b1.size() - d - 1];
            int v2 = b2.back();
            std::cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
            for (int i = 0; i < d; ++i) {
                b1.pop_back();
            }
            for (auto i : qq) {
                b2.push_back(i);
            }
        }
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
